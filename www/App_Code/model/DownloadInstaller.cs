using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
//-----------------------------------------------------------------------------
namespace model
{
    //-----------------------------------------------------------------------------
    /// <summary>
    /// Summary description for DownloadInstaller
    /// </summary>
    //-----------------------------------------------------------------------------
    public class DownloadInstaller
    {
        string m_strCustomerId = "";
        string m_strLicenseId = "";
        string m_strProductId = "";

        //-----------------------------------------------------------------------------
        public DownloadInstaller(string strCustomerId,
                                 string strLicenseId,
                                 string strProductId)
        {
            m_strCustomerId = strCustomerId;
            m_strLicenseId = strLicenseId;
            m_strProductId = strProductId;

            data.Log.debug("DownloadInstaller created");
        }

        //-----------------------------------------------------------------------------
        public bool isValidLicense()
        {
            data.Log.debug("isValidLicense start");
            string strId = "";

            //triple check here, id, customerid and product id.
            string strSqlStatement = "SELECT id FROM License where customerid = " +
                "'" + m_strCustomerId + "'" +
                "AND productid = " +
                "'" + m_strProductId + "';";

            try
            {
                strId = data.Database.readFromDataBase(strSqlStatement);
            }
            catch (Exception e)
            {
                data.Log.debug("isValidLicense exception = " + e.Message.ToString());
                return false;
            }

            if (strId == m_strLicenseId)
            {
                data.Log.debug("strId = m_strLicenseId = " + m_strLicenseId);
                return true;
            }
            else
            {
                data.Log.debug("diffs: [strId = " + strId + "] != [m_strLicenseId = " + m_strLicenseId + "]");
                return false;
            }
        }

        //-----------------------------------------------------------------------------
        public string getFilePath()
        {
            data.Log.debug("getFilePath start");
            string strPath = "";

            string strProductName = getProductName();
            if ("" == strProductName)
            {
                data.Log.debug("strProductName is \"\". return \"\" ");
                return "";
            }
            string strProductVersion = getProductVersion();
            if (strProductVersion == "")
            {
                data.Log.debug("strProductVersion is \"\". return \"\" " );
                return "";
            }

            string strSqlStatement = " select filepath from ImageFile " +
                " WHERE productname = '" + strProductName + "' " +
                " AND productversion = '" + strProductVersion + "' " +
                " AND active = 1;";

            data.Log.debug("sql statement = " + strSqlStatement);

            try
            {
                strPath = data.Database.readFromDataBase(strSqlStatement);
            }
            catch (Exception e)
            {
                data.Log.debug("exception e = " + e.Message.ToString());
                strPath = "no_path_found_in_the_database";
            }

            data.Log.debug("getFilePath end. strPath = " + strPath);
            return strPath;
        }

        //-----------------------------------------------------------------------------
        public string getFileRealName(string strFilePath)
        {
            data.Log.debug("getFileRealName start");

            string strRealName = "";
            string strProductName = getProductName();
            if ("" == strProductName)
            {
                return "";
            }
            string strProductVersion = getProductVersion();
            if (strProductVersion == "")
            {
                return "";
            }

            string strSqlStatement = " select filename from ImageFile " +
                " WHERE productname = '" + strProductName + "'" +
                " AND productversion = '" + strProductVersion + "'" +
                " AND active = 1;";

            data.Log.debug("strSqlStatement = " + strSqlStatement);

            try
            {
                strRealName = data.Database.readFromDataBase(strSqlStatement);
                data.Log.debug("strRealName = " + strRealName);
            }
            catch (Exception e)
            {
                data.Log.debug("sql exception e = " + e.Message.ToString());

                strRealName = "";
            }

            strRealName += ".Setup.msi";
            data.Log.debug("getFileRealName end; strRealName = " + strRealName);

            return strRealName;
        }

        //-----------------------------------------------------------------------------
        public string getProductName()
        {
            data.Log.debug("getProductName end");

            string strProductName = "";
            string strSqlStatement = "SELECT productname from License " +
                "WHERE id = '" + this.m_strLicenseId + "';";

            data.Log.debug("strSqlStatement = " + strSqlStatement);

            try
            {
                strProductName = data.Database.readFromDataBase(strSqlStatement);
                data.Log.debug("strProductName = " + strProductName);
            }
            catch (Exception e)
            {
                data.Log.debug("getProductName exception e = " + e.Message.ToString());
                strProductName = "";
            }

            data.Log.debug("getProductName end");
            return strProductName;
        }

        //-----------------------------------------------------------------------------
        public string getProductVersion()
        {
            data.Log.debug("getProductVersion start");

            string strProductVersion = "";
            string strSqlStatement = "SELECT productversion from License " +
                "WHERE id = '" + this.m_strLicenseId + "';";

            data.Log.debug("strSqlStatement = " + strSqlStatement);

            try
            {
                strProductVersion = data.Database.readFromDataBase(strSqlStatement);

                data.Log.debug("strProductVersion = " + strProductVersion);
            }
            catch (Exception e)
            {
                data.Log.debug("strProductVersion exception = " + e.Message.ToString());
                strProductVersion = "";
            }

            data.Log.debug("getProductVersion end. strProductVersion  = " + strProductVersion);
            return strProductVersion;
        }

        //-----------------------------------------------------------------------------
        public bool isValidDateIntervalForDownload()
        {
            data.Log.debug("isValidDateIntervalForDownload start");

            //up to 24 hours it is a valid date
            string strDifference = "25";

            string strSqlStatement =
                " SELECT DATEDIFF(hour," + 
                " (SELECT emaildate " + 
                " FROM License " +
                " WHERE id = '" + m_strLicenseId + " '" + 
                "), CURRENT_TIMESTAMP) FROM License;";

            data.Log.debug("strSqlStatement = " + strSqlStatement);

            try
            {
                strDifference = data.Database.readFromDataBase(strSqlStatement);

                data.Log.debug("strDifference = " + strDifference);
            }
            catch (Exception e)
            {
                data.Log.debug("exception in diff = " + e.Message.ToString());
                strDifference = "25";
            }

            if (strDifference == "")
            {
                data.Log.debug("diff = \"\" return false");
                return false;
            }

            try
            {
                int iDiff = Int32.Parse(strDifference);

                if (iDiff > 24 || iDiff < 0)
                {
                    data.Log.debug("diff = " + iDiff + ", return false");
                    return false; // 1 day for download is gone
                }
            }
            catch (Exception e)
            {
                data.Log.debug("last exception = " + e.Message.ToString() + ", return false");
                return false; // 1 day for download is gone
            }

            data.Log.debug("isValidDateIntervalForDownload end, return true");
            return true; //within 1 days of download
        }
        //-----------------------------------------------------------------------------
    }
    //-----------------------------------------------------------------------------
}
//-----------------------------------------------------------------------------
