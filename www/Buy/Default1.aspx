<%@ Page Language="C#" MasterPageFile="~/AppMaster.master" AutoEventWireup="true" 
    CodeBehind="Default1.aspx.cs" Inherits="jewelleryonpc.Buy.Buy_Default"  
    Title="Buy jewelleryonpc software" %>

<asp:Content runat="server" ContentPlaceHolderID="mainCopy">

    <div class="container" id="sandboxForm">
        <h2>
            3D Ringonpc Jewellery designer</h2>
        <h2>
            Buy with PayPal from the Sandbox</h2>
        <p>
            &nbsp;</p>
        <p>
            This is the sandbox button</p>
        <p>
            &nbsp;</p>

    <input type="hidden" name="cmd" value="_s-xclick"/>
    <input type="hidden" name="hosted_button_id" value="27743"/>

    <asp:ImageButton ID="Button2" runat="server" 
            ImageUrl="https://www.sandbox.paypal.com/en_US/i/btn/btn_buynowCC_LG.gif"       
            PostBackUrl="https://www.sandbox.paypal.com/cgi-bin/webscr" 
            AlternateText="PayPal - The safer, easier way to pay online!" 
            Height="61px" Width="176px" /><br />
        <br />
        <br />
        This is the prod button<br />
        <br />
        <br />

        <input  type="hidden" name="cmd" value="_s-xclick"/>
   <!-- --------------------------------------------------------------------
        enable this and remove the hidded ones from sandbox 
   --------------------------------------------------------------------
        <input  type="hidden" name="encrypted" 
                value="-----BEGIN PKCS7----- blah blah blah -----END PKCS7-----"/>
    -->

        <asp:ImageButton ID="ImageButton1" runat="server" 
            ImageUrl="https://www.sandbox.paypal.com/en_US/i/btn/btn_buynowCC_LG.gif"       
            PostBackUrl="https://www.paypal.com/cgi-bin/webscr" 
            AlternateText="PayPal - The safer, easier way to pay online!" 
            Height="61px" Width="176px" />

    </div>    
</asp:Content>