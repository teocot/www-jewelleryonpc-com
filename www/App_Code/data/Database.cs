using System;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Configuration;

namespace data
{
    /// <summary>
    /// Summary description for Database
    /// </summary>
    public class Database
    {
        static string m_strConnectionString = "";
        static bool m_bGotConnectionString = false;

        public Database()
        {
            //
            // TODO: Add constructor logic here
            //
        }

        public static string getConnectionString()
        {
            if (m_bGotConnectionString)
            {
                return m_strConnectionString;
            }

            string strSystem = ConfigurationManager.AppSettings["SYSTEM"];

            if (strSystem == "PROD")
            {
                 m_strConnectionString = ConfigurationManager.AppSettings["CONNECTION_STRING_PROD"];
            }
            else
            {
                 m_strConnectionString = ConfigurationManager.AppSettings["CONNECTION_STRING_DEV"];
            }

            m_bGotConnectionString = true;

            return m_strConnectionString;
        }

        public static string readFromDataBase(string strSqlStatement)
        {
            if (!m_bGotConnectionString)
            {
                getConnectionString();
            }

            string strValue = "";

            SqlConnection sqlCn = new SqlConnection(m_strConnectionString);
            SqlCommand cmCustomer = new SqlCommand(strSqlStatement, sqlCn);

            sqlCn.Open();

            SqlDataReader sqlDr  = cmCustomer.ExecuteReader();

            do
            {
                while (sqlDr.Read())
                {
                    strValue = sqlDr[0].ToString();
                }
            } while (sqlDr.NextResult());

            strValue = strValue.Trim();

            data.Log.debug(strValue + " = " + strSqlStatement);

            sqlDr.Close();
            sqlCn.Close();
            sqlCn.Dispose();
            sqlCn = null;
            return strValue;
        }

        public static string readMeshFromDataBase(string strSqlStatement)
        {
            if (!m_bGotConnectionString)
            {
                getConnectionString();
            }

            string strValue = "";

            SqlConnection sqlCn = new SqlConnection(m_strConnectionString);
            SqlCommand cmCustomer = new SqlCommand(strSqlStatement, sqlCn);

            sqlCn.Open();

            SqlDataReader sqlDr = cmCustomer.ExecuteReader();

            do
            {
                while (sqlDr.Read())
                {
                    strValue = sqlDr[0].ToString();
                }
            } while (sqlDr.NextResult());

            strValue = strValue.Trim();

            data.Log.debug("strSqlStatment = " + strSqlStatement);

            sqlDr.Close();
            sqlCn.Close();
            sqlCn.Dispose();
            sqlCn = null;
            return strValue;
        }

        public static int writeToDataBase(string strSqlStatement)
        {
            int noRowsAffected = 0 ;
            if (!m_bGotConnectionString)
            {
                getConnectionString();
            }
            
            try
            {

                SqlConnection sqlCn = new SqlConnection(m_strConnectionString);
                SqlCommand cmCustomer = new SqlCommand(strSqlStatement, sqlCn);

                sqlCn.Open();
                noRowsAffected = cmCustomer.ExecuteNonQuery();

                sqlCn.Close();
                sqlCn.Dispose();
                sqlCn = null;
            }
            catch(SqlException ex)
            {
                throw ex;
            }
            return noRowsAffected;
        }

        //we have to query database for that
        public static bool wasPaymentAlreadyProcessed(string txn_id)
        {
            data.Log.debug("wasPaymentAlreadyProcessed for txn_id = " + txn_id);

            string strValue = "";

            strValue = readFromDataBase(
                           "select number from customer where txn_id = " +
                           "'" + txn_id + "';" );

            if (strValue == txn_id)
            {
                return true;
            }
            return false;
        }

        public static string getProductAmount(string str_item_name, string str_item_number)
        {
            data.Log.debug("getProductAmount for: [" + str_item_name + "," + str_item_number + "]");

            string strValue = "";

            string strSqlStatement =   "SELECT price FROM ImageFile where productname = " +
                                       "'" + str_item_name + "'" +
                                       " AND productversion = " +
                                       "'" + str_item_number + "';";

            data.Log.debug("strSqlStatement is: " + strSqlStatement);
            strValue = readFromDataBase(strSqlStatement);

            return strValue;
        }

        public static string getProductCurrency(string str_item_name, string str_item_number)
        {
            data.Log.debug("getProductCurrency for: [" + str_item_name + "," + str_item_number + "]");

            string strValue = "";

            string strSqlStatement = "SELECT currency FROM ImageFile where productname = " +
                                       "'" + str_item_name + "'" +
                                       " AND productversion = " +
                                       "'" + str_item_number + "';";

            data.Log.debug("strSqlStatement is: " + strSqlStatement);
            strValue = readFromDataBase(strSqlStatement);
            
            return strValue;
        }
    }
}