<%@ Page Language="C#" 
    MasterPageFile="~/AppMaster.Master" 
    AutoEventWireup="true" 
    CodeBehind="Default.aspx.cs" 
    Inherits="jewelleryonpc.Buy.Default" 
    Title="Buy ringonpc birthstone" %>

<asp:Content ID="Content1" runat="server" ContentPlaceHolderID="mainCopy">

    <div class="container" id="sandboxForm">
        <h2>
            Ringonpc Birthstone version 1.0</h2>
        <p>
            Price: $120 USD</p>
        <p>
            You can buy with PayPal by clicking the button below:</p>
        <p>
            &nbsp;

<!-- button with email address field and IPN -->
<!--

-->

   <!-- --------------------------------------------------------------------
        enable this and remove the hidded ones from sandbox 
   --------------------------------------------------------------------
    -->

        <input type="hidden" name="cmd" value="_s-xclick" />
        <input type="hidden" name="hosted_button_id" value="5498474" />
        <asp:ImageButton ID="ImageButton1" runat="server" 
            ImageUrl="https://www.paypal.com/en_US/i/btn/btn_buynowCC_LG.gif"       
            PostBackUrl="https://www.paypal.com/cgi-bin/webscr" 
            AlternateText="PayPal - The safer, easier way to pay online!" 
            Height="44px" Width="127px" />
        <img alt="" border="0" src="https://www.paypal.com/en_US/i/scr/pixel.gif" 
             width="1" height="1" />
        <br />
        <br />
            Once the payment is completed, we will send you an email with the license details and
            instructions how to download the program. Usually it takes a few minutes to
            receive the email, after the payment is completed.</p>
        <p>
        For additional informations or if there are any queries regarding the email and
            the download link, please email us at:<br />
            <a href="mailto: contact@jewelleryonpc.com" style="color: blue; text-decoration: underline">
                contact@jewelleryonpc.com</a> or go to <a href="../Contact.aspx" style="color: Blue; text-decoration: underline">ContactUs</a>
            page and send us a message.</p>
    </div>    
</asp:Content>
