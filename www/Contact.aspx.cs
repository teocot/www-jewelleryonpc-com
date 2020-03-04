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
using model;

namespace jewelleryonpc
{
    public partial class Contact : System.Web.UI.Page
    {
        string str_txtName = "teo";
        string str_txtEmail = "teodor@xtra.co.nz";
        string str_rblImportance = "low";
        string str_txtMessage = "this is the message, low, sure";
        string str_rblSubscribe = "true";
        
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
                txtName.Focus();
        }

        public void showRequest()
        {
            string strResponse = "";

            str_txtName = txtName.Text;
            str_txtEmail = txtEmail.Text;
            str_rblImportance = rblImportance.Text;
            str_txtMessage = txtMessage.Text;
            str_rblSubscribe = rblSubscribe.Text;

            strResponse += str_txtName;
            strResponse += str_txtEmail;
            strResponse += str_rblImportance;
            strResponse += str_txtMessage;
            strResponse += str_rblSubscribe;

            Response.ClearHeaders();
            Response.ClearContent();
            Response.Clear();
            Response.ContentType = "text/plain";
            Response.Write(strResponse);
            Response.End();

        }

        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            str_txtName = txtName.Text;
            str_txtEmail = txtEmail.Text;
            str_rblImportance = rblImportance.Text;
            str_txtMessage = txtMessage.Text;
            str_rblSubscribe = rblSubscribe.Text;

            ContactUs contactUs = new ContactUs(str_txtName, 
                                                str_txtEmail, 
                                                str_rblImportance,
                                                str_txtMessage, 
                                                str_rblSubscribe);
            contactUs.send();

            reset();

            //this was used to debug application
//          showRequest();

        }

        public void reset()
        {
            txtName.Text = "";
            txtEmail.Text = "";
            txtMessage.Text = "";
        }
    }
}