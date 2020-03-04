using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Net;
using System.Net.Mail;
using System.IO;
using System.Text;
using System.Xml;
using license;

namespace model
{
    /// <summary>
    /// Summary description for EmailDownload
    /// </summary>
    public class ContactUs
    {
        string m_strTo = "helenw.williams@xtra.co.nz";
        string m_strFrom = "contact@jewelleryonpc.com";
        string m_strSmtpServer = "";

        string m_strUserName = "SomeVisitor";
        string m_strUserEmailAddress = "UserEmail";
        string m_strImportance = "High";
        string m_strBody = "";
        string m_strSubscribe = "No, thanks";

        public ContactUs(   string strUserName, 
                            string strUserEmailAddress,
                            string strImportance,
                            string strBody,
                            string strSubscribe)
        {

            readMailConfig();

            m_strUserName           = strUserName;
            m_strUserEmailAddress   = strUserEmailAddress;
            m_strImportance         = strImportance;
            m_strBody               = strBody;
            m_strSubscribe          = strSubscribe;
        }

        public void readMailConfig()
        {
            m_strTo = ConfigurationManager.AppSettings.Get("SENDER_EMAIL_PROD");
            m_strFrom = m_strTo;
        }

        public int send()
        {
         
            MailMessage mailMessage = createEmail();
            string strSmtpServer = ConfigurationManager.AppSettings.Get(m_strSmtpServer);
//            data.Log.debug("strSmtpServer = " + strSmtpServer);

            SmtpClient client = new SmtpClient(strSmtpServer, 25);


            string strSystem = ConfigurationManager.AppSettings.Get("SYSTEM");
            if (strSystem == "DEV")
            {
  //              data.Log.debug("this is DEV ");
                client.Host = ConfigurationManager.AppSettings.Get("SMTP_HOST_DEV");
    //            data.Log.debug("client.Host = " + client.Host);
            }
            else if (strSystem == "PROD")
            {
      //          data.Log.debug("this is PROD ");
                client.Host = ConfigurationManager.AppSettings.Get("SMTP_HOST_PROD");
        //        data.Log.debug("client.Host = " + client.Host);
            }
            else
            {
          //      data.Log.debug("this is not DEV and not PROD. It is UNKNOWN ");
                return -1;
            }

            client.Port = 25;

            if (strSystem == "DEV")
            {
                client.DeliveryMethod = SmtpDeliveryMethod.SpecifiedPickupDirectory;
                client.PickupDirectoryLocation = "D:/dev/mail";
            }
            else if (strSystem == "PROD")
            {
                client.DeliveryMethod = SmtpDeliveryMethod.Network;
            }
            else
            {
                return -1;
            }

            mailMessage.Priority = MailPriority.High;
            MailAddress bcc = new MailAddress("helenw.williams@xtra.co.nz");
            mailMessage.Bcc.Add(bcc);

            string strCredentialsUser = "";
            string strCredentialsPassword = "";
            if (strSystem == "DEV")
            {
                strCredentialsUser = ConfigurationManager.AppSettings.Get("NET_USER_LOGIN_DEV");
                strCredentialsPassword = ConfigurationManager.AppSettings.Get("NET_USER_PASS_DEV");

            }
            else if (strSystem == "PROD")
            {
                strCredentialsUser = ConfigurationManager.AppSettings.Get("NET_USER_LOGIN_PROD");
                strCredentialsPassword = ConfigurationManager.AppSettings.Get("NET_USER_PASS_PROD");
            }
            else
            {
                data.Log.debug("ERROR in credentials and password");
                return -1;
            }
//            data.Log.debug("strCredentialsUser = " + strCredentialsUser);
  //          data.Log.debug("strCredentialsPassword = " + strCredentialsPassword);

            client.Credentials = new System.Net.NetworkCredential(  strCredentialsUser, 
                                                                    strCredentialsPassword);
            try
            {
    //            data.Log.debug("try to send email");
                client.Send(mailMessage);
      //          data.Log.debug("email sent");
            }
            catch (System.Net.Mail.SmtpFailedRecipientException)
            {
        //        data.Log.debug("SmtpFailedRecipientException in sending email: " + ex.Message.ToString());
                return -1;
            }
            catch (System.Exception)
            {
          //      data.Log.debug("Exception in sending email: " + e.Message.ToString());
                return -1;
            }

            return 0;
        }

        private MailMessage createEmail()
        {
  //          data.Log.debug("ContactUs.createEmail started");

            MailAddress toAddress = new System.Net.Mail.MailAddress(m_strTo);
            MailAddress fromAddress = new MailAddress(m_strFrom);

            MailMessage msg = new MailMessage(fromAddress, toAddress);
            msg.IsBodyHtml = false;
            msg.BodyEncoding = System.Text.Encoding.ASCII;

            //here we should load it
            string strMessage = "";
            strMessage += "UserName     = " + m_strUserName         + "\n";
            strMessage += "UserEmail    = " + m_strUserEmailAddress + "\n"; 
            strMessage += "Message      = " + m_strBody             + "\n";
            strMessage += "Subscribe    = " + m_strSubscribe        + "\n";
            msg.Body = strMessage;
            msg.Subject = m_strUserName + " - Contacted Us";

//            data.Log.debug("ContactUs.createEmail ended");

            return msg;
        }

    }
}