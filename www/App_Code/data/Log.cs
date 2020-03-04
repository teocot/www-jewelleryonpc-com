using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.IO;

namespace data
{
    /// <summary>
    /// Summary description for Log
    /// </summary>
    public class Log
    {
        private static string getTime()
        {
            string strTime = "";
            int year = DateTime.Now.Year;
            int month = DateTime.Now.Month;
            int day = DateTime.Now.Day;
            int hour = DateTime.Now.Hour;
            int min = DateTime.Now.Minute;
            int sec = DateTime.Now.Second;
            int mil = DateTime.Now.Millisecond;

            if (day < 10) strTime += "0";
            strTime += day.ToString() + ":";
            if (month < 10) strTime += "0" + month.ToString() + ":";
            strTime += year.ToString() + " "; 
            strTime += (hour < 10) ? "0" + hour.ToString() : hour.ToString();
            strTime += ":" + ((min < 10) ? "0" + min.ToString() : min.ToString());
            strTime += ":" + ((sec < 10) ? "0" + sec.ToString() : sec.ToString());
            strTime += ":";
            if (mil < 10) strTime += "00";
            if (mil > 10 && mil < 100 ) strTime += "0";
            strTime += mil.ToString();

            return strTime;
        }

        private static string fileName =
            HttpContext.Current.Server.MapPath("~/App_Data/log.txt");
        private static Log m_log = null;
        private static Object synchronizeVariable = "locking";
        private static StreamWriter sw = null; 
        
        public static Log getInstance()
        {
            if (m_log == null)
                m_log = new Log();
            return m_log;
        }

        public static void setFileName(string fileName)
        {
        }

        private Log()
        {
            lock (synchronizeVariable)
            {
                if (!File.Exists(fileName))
                {
                    sw = File.CreateText(fileName);

                    sw.WriteLine("\n----------------start run -------------------------");
                    sw.Flush();
                    sw.Close();
                }
                else
                {
                    sw = File.AppendText(fileName);
                    sw.WriteLine("\n----------------start run -------------------------");
                    sw.Flush();
                    sw.Close();
                }
            }
        }

        public static void debug(string strValue)
        {
            if (m_log == null)
            {
                getInstance();
            }

//            lock (synchronizeVariable)
            {
                sw = File.AppendText(fileName);
                sw.WriteLine("[" + getTime() + "] " + strValue);
                sw.Flush();
                sw.Close();
            }
        }

    }
}//namespace data

