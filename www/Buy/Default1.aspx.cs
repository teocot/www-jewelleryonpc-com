using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

using System.IO;
using System.Text;
using System.Net;

namespace jewelleryonpc.Buy {

    public partial class Buy_Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            /*        //Post back to either sandbox or live
                    string strPayPalUrl;
            //        if (ConfigurationManager.AppSettings.Get("PAYPAL") == "SANDBOX")
                    {
                        strPayPalUrl = "https://www.sandbox.paypal.com/cgi-bin/webscr";
                    }


                    HttpWebRequest req = (HttpWebRequest)WebRequest.Create(strPayPalUrl);

                    //Set values for the request back
                    req.Method = "POST";
                    req.ContentType = "application/x-www-form-urlencoded";
                    byte[] param = Request.BinaryRead(HttpContext.Current.Request.ContentLength);

                    string strRequest;
                    if (isProd)
                    {
                        strRequest = Encoding.ASCII.GetString(param);
                        strRequest += "&cmd=_notify-validate";
                        data.Log.debug("Prod strRequest = " + strRequest);
                    }
                    else
                    {
                        strRequest = "test_ipn=1&payment_type=instant&payment_date=18%3A36%3A53+Jan.+26%2C+2009+PST&payment_status=Completed&payer_status=verified&first_name=John&last_name=Smith&payer_email=teodor%40xtra.co.nz&payer_id=TESTBUYERID01&business=teodor%40xtra.co.nz&receiver_email=teodor%40xtra.co.nz&receiver_id=TESTSELLERID1&residence_country=US&item_name=ItemName&item_number=AK-1234&quantity=1&tax=2.02&mc_currency=USD&mc_fee=0.44&mc_gross=15.34&mc_gross1=12.34&mc_handling=2.06&mc_handling1=1.67&mc_shipping=3.02&mc_shipping1=1.02&txn_type=cart&txn_id=53127236&notify_version=2.4&custom=xyz123&invoice=abc1234&charset=windows-1252&verify_sign=AVpeML361chUtRBQ48IYKP.PoLJIABQkl3lLa.7uTndxeDz7.kmUQYcc&cmd=_notify-validate";
                        data.Log.debug("Dev strRequest = " + strRequest);
                    }

                    req.ContentLength = strRequest.Length;
                    //for proxy
                    //WebProxy proxy = new WebProxy(new Uri("http://url:port#"));
                    //req.Proxy = proxy;

                    //Send the request to PayPal and get the response
                    StreamWriter streamOut = new StreamWriter(req.GetRequestStream(), System.Text.Encoding.ASCII);
                    streamOut.Write(strRequest);
                    streamOut.Close();

                    StreamReader streamIn = new StreamReader(req.GetResponse().GetResponseStream());
                    string strResponse = streamIn.ReadToEnd();
                    streamIn.Close();


                    String strFlag = Request.Form.Get("redirectflag");
                    if (strFlag == "true")
                    {
                        Response.Redirect(strPayPalUrl, true);
                    }
            */

        }
    }
}
