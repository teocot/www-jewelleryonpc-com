using System;
using System.Data;
using System.Data.SqlClient;
using System.Data.Odbc;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using data;

namespace model
{
    /// <summary>
    /// Summary description for Customer
    /// </summary>
    public class Customer
    {
        public IPN m_ipn = new IPN();
        private Customer()
        {
        }

        public Customer(IPN ipn)
        {
            m_ipn = ipn;
        }

        public string readFromDataBase()
        {
            string returnValue = null;
            returnValue = Database.readFromDataBase("SELECT * FROM CUSTOMER");

            return returnValue;
        }

        //sample:
/*
 * insert into customer 
(number, email,date,payment_status,first_name,last_name,payer_email,
 receiver_email,item_name,item_number,quantity,tax,mc_currency,
 mc_gross,txn_id) 
values('123456789','helen@jewelleryonpc.com',CURRENT_TIMESTAMP,
'completed','Teodor','LAstname','teodor@xtra.co.nz','helenw.williams@xtra.co.nz',
'ringonpc','1.0','1','12.5','USD','110.00','123456789')
*/
        public int writeToDataBase()
        {
            int strReturnValue = -1;
            try
            {
                string sqlSqlStatement =
                    "insert into customer " +
                    "(" +
                    "number," +
                    "email," +
                    "date," +
                    "payment_status," +
                    "first_name," +
                    "last_name," +
                    "payer_email," +
                    "receiver_email," +
                    "item_name," +
                    "item_number," +
                    "quantity," +
                    "tax," +
                    "mc_currency," +
                    "mc_gross," +
                    "txn_id)" +
                    "values(" +
                    "'" + m_ipn.str_txn_id + "'," +
                    "'" + m_ipn.str_payer_email + "'," +
                    "CURRENT_TIMESTAMP," +
                    //                    m_ipn.str_date + "'," +
                    "'" + m_ipn.str_payment_status + "'," +
                    "'" + m_ipn.str_first_name + "'," +
                    "'" + m_ipn.str_last_name + "'," +
                    "'" + m_ipn.str_payer_email + "'," +
                    "'" + m_ipn.str_receiver_email + "'," +
                    "'" + m_ipn.str_item_name + "'," +
                    "'" + m_ipn.str_item_number + "'," +
                    "'" + m_ipn.str_quantity + "'," +
                    "'" + m_ipn.str_tax + "'," +
                    "'" + m_ipn.str_mc_currency + "'," +
                    "'" + m_ipn.str_mc_gross + "'," +
                    "'" + m_ipn.str_txn_id + "');";

                strReturnValue = Database.writeToDataBase(sqlSqlStatement);

                data.Log.debug(strReturnValue + "Insert customer: " + sqlSqlStatement);
            }
            catch (System.Data.SqlClient.SqlException ex1)
            {
                string strError = ex1.Message;

                string sqlSqlStatement =
                    "insert into customer (number, email, date, error) " +
                    "values ( 0000, 'teodor@xtra.co.nz', CURRENT_TIMESTAMP, '"+
                    strError + "');";

                try
                {
                    strReturnValue = Database.writeToDataBase(sqlSqlStatement);
                }
                catch (System.Exception e)
                {
                    data.Log.debug("Some problems in writeToDataBase" +
                                        e.Message);
                }

                //we should log somthing here:
                data.Log.debug("Exception inserting data: " + ex1.Message);
            }

            return strReturnValue;
        }

        public int writeToFullDataBase()
        {
            int strReturnValue = -1;
            try
            {
                string sqlSqlStatement =
                    "insert into customer " +
                    "(" +
                    "number," +
                    "email," +
                    "date," +
                    "payment_type," +
                    "payment_status," +
                    "payer_status," +
                    "first_name," +
                    "last_name," +
                    "payer_email," +
                    "payer_id," +
                    "business," +
                    "receiver_email," +
                    "residence_country," +
                    "item_name," +
                    "item_number," +
                    "quantity," +
                    "tax," +
                    "mc_currency," +
                    "mc_fee," +
                    "mc_gross," +
                    "mc_gross1," +
                    "mc_handling," +
                    "mc_handling1," +
                    "mc_shipping, " +
                    "mc_shipping1," +
                    "txn_type," +
                    "txn_id," +
                    "notify_version," +
                    "custom, invoice, charset, verify_sign, cmd)" +
                    "values(" +
                    "'" + m_ipn.str_txn_id + "'," +
                    "'" + m_ipn.str_payer_email + "'," +
                    "CURRENT_TIMESTAMP," +
                    //                    m_ipn.str_date + "'," +
                    "'" + m_ipn.str_payment_type + "'," +
                    "'" + m_ipn.str_payment_status + "'," +
                    "'" + m_ipn.str_payer_status + "'," +
                    "'" + m_ipn.str_first_name + "'," +
                    "'" + m_ipn.str_last_name + "'," +
                    "'" + m_ipn.str_payer_email + "'," +
                    "'" + m_ipn.str_payer_id + "'," +
                    "'" + m_ipn.str_business + "'," +
                    "'" + m_ipn.str_receiver_email + "'," +
                    "'" + m_ipn.str_residence_country + "'," +
                    "'" + m_ipn.str_item_name + "'," +
                    "'" + m_ipn.str_item_number + "'," +
                    "'" + m_ipn.str_quantity + "'," +
                    "'" + m_ipn.str_tax + "'," +
                    "'" + m_ipn.str_mc_currency + "'," +
                    "'" + m_ipn.str_mc_fee + "'," +
                    "'" + m_ipn.str_mc_gross + "'," +
                    "'" + m_ipn.str_mc_gross1 + "'," +
                    "'" + m_ipn.str_mc_handling + "'," +
                    "'" + m_ipn.str_mc_handling1 + "'," +
                    "'" + m_ipn.str_mc_shipping + "'," +
                    "'" + m_ipn.str_mc_shipping1 + "'," +
                    "'" + m_ipn.str_txn_type + "'," +
                    "'" + m_ipn.str_txn_id + "'," +
                    "'" + m_ipn.str_notify_version + "'," +
                    "'" + m_ipn.str_custom + "'," +
                    "'" + m_ipn.str_invoice + "'," +
                    "'" + m_ipn.str_charset + "'," +
                    "'" + m_ipn.str_verify_sign + "'," +
                    "'" + m_ipn.str_cmd + "');";

                strReturnValue = Database.writeToDataBase(sqlSqlStatement);
            }
            catch (System.Data.SqlClient.SqlException ex1)
            {
                string sqlSqlStatement =
                    "insert into customer (number, email, date) " +
                    "values ( 0000, 'teodor@xtra.co.nz', CURRENT_TIMESTAMP);";

                try
                {
                    strReturnValue = Database.writeToDataBase(sqlSqlStatement);
                }
                catch (System.Exception e)
                {
                    data.Log.debug("Some problems in writeToFullDataBase" + 
                                        e.Message);
                }

                data.Log.debug("Exception inserting data: " + ex1.Message);
            }

            return strReturnValue;
        }

        public int attachLicense(license.License lic)
        {
            int noRowsAffected = 0;

            string strSqlStatement = "insert into License " + 
                "(name, productname, productversion, customerid, customername, " +
                 "customeremail, productid, generatedkey, creationdate) " +
                 "values (" +
                 " 'license name','" +
                 this.m_ipn.str_item_name +  "','" + 
                 this.m_ipn.str_item_number +  "','" +
                 this.m_ipn.str_txn_id +  "','" +
                 this.m_ipn.str_first_name + " " + this.m_ipn.str_last_name + "','" +
                 this.m_ipn.str_payer_email + "','" +
                 lic.s_strProductID +  "','" +
                 lic.s_strSoftwareKey +  "'," +
                 " CURRENT_TIMESTAMP ); ";
            try
            {
                noRowsAffected = Database.writeToDataBase(strSqlStatement);
            }
            catch (System.Exception e)
            {
                data.Log.debug("Some problems in attachLicense, try default" +
                    e.Message);
                string strSqlStatement2 = "insert into License " +
                    "(name, productname, productversion, customerid, " +
                     "customeremail, productid, generatedkey, creationdate) " +
                     "values (" +
                     "'license ERROR','" +
                     "str_item_name " + "','" +
                     "str_item_number " + "','" +
                     "str_txn_id" + "','" +
                     "str_payer_email" + "','" +
                     "s_strProductID" + "','" +
                     "s_strSoftwareKey" + "'," +
                     " CURRENT_TIMESTAMP " +
                     ");";
                try
                {
                    Database.writeToDataBase(strSqlStatement2);
                    noRowsAffected = 0;
                }
                catch (System.Exception e2)
                {
                    data.Log.debug("Some problems in attachLicense" +
                        e2.Message);
                    noRowsAffected = 0;
                } 
            }

            if (noRowsAffected != 1)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

        public int updateLicenseEmailDate(bool emailSentOk, license.License lic)
        {
            int noRowsAffected = 0;
            int iEmailOk = 0;// false, 1 will be ok
            if (emailSentOk)
            {
                iEmailOk = 1;
            }

            string strSqlStatement = "update License " +
                "set emailsent = " + iEmailOk + "," +
                " emaildate = CURRENT_TIMESTAMP " +
                 "WHERE productid = '" + lic.s_strProductID + "';";
            try
            {
                noRowsAffected = Database.writeToDataBase(strSqlStatement);
            }
            catch (System.Exception e)
            {
                data.Log.debug("Some problems in attachLicense" +
                    e.Message);
                noRowsAffected = 0;
            }

            if (noRowsAffected != 1)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

        public string getLicenseId(license.License lic)
        {
            string strLicenseId; 

            string strSqlStatement = "select id from License " +
                 "WHERE  productid = '" + lic.s_strProductID + "';";
            try
            {
                strLicenseId = Database.readFromDataBase(strSqlStatement);
            }
            catch (System.Exception e)
            {
                data.Log.debug("Some problems in attachLicense" + e.Message);
                return "InvalidNumber";
            }

            return strLicenseId;
        }
    }

}