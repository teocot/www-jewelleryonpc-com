<%@ Page Language="C#" MasterPageFile="~/AppMaster.Master" AutoEventWireup="true" 
     CodeBehind="Contact.aspx.cs" Inherits="jewelleryonpc.Contact" Title="Contact Us" %>

<asp:Content ID="Content1" ContentPlaceHolderID="mainCopy" runat="Server">
    <div class="container">
        <h1>Contact Us</h1>
        <p>
            You can send us a message using the form below<span style="color: #0000ff">*</span>:
        </p>
        <div id="contactForm">
            <fieldset style="width: 300px;">
                <legend>Who you are</legend>
                <asp:Label ID="Label1" runat="server" AssociatedControlID="txtName" Text="<u>N</u>ame" /><br />
                <asp:TextBox ID="txtName" runat="server" AccessKey="n" TabIndex="10" /><br />
                <asp:Label ID="Label2" runat="server" AssociatedControlID="txtEmail" Text="E<u>m</u>ail address" /><br />
                <asp:TextBox ID="txtEmail" runat="server" AccessKey="m" TabIndex="11" /></fieldset>
            <fieldset style="width: 300px;">
                <legend>What you have to say</legend>
                <asp:Label ID="Label4" runat="server" AssociatedControlID="rblImportance" Text="Importance:" />
                <asp:RadioButtonList ID="rblImportance" runat="server" RepeatDirection="Horizontal"
                    RepeatLayout="Flow" TabIndex="13">
                    <asp:ListItem Value="low">Low</asp:ListItem>
                    <asp:ListItem Selected="True" Value="normal">Normal</asp:ListItem>
                    <asp:ListItem Value="high">High</asp:ListItem>
                </asp:RadioButtonList><br />
                <br />
                <asp:Label ID="Label5" runat="server" AssociatedControlID="txtMessage" Text="M<u>e</u>ssage" /><br />
                <asp:TextBox ID="txtMessage" runat="server" TextMode="MultiLine" Columns="30" Rows="6"
                    AccessKey="e" TabIndex="14" />
            </fieldset>
            <fieldset style="width: 300px;">
                <legend>Subscribe to Newsletter?</legend>
                <asp:RadioButtonList ID="rblSubscribe" runat="server" TabIndex="15">
                    <asp:ListItem Selected="True" Value="true">Sure.</asp:ListItem>
                    <asp:ListItem Value="false">No, thanks.</asp:ListItem>
                </asp:RadioButtonList>
            </fieldset>
            <div style="margin-top: 1em;">
                <asp:Button ID="btnSubmit" runat="server" Text="Send" TabIndex="16" AccessKey="d" OnClick="btnSubmit_Click" />
                <br />
                <br />
                <span style="font-size: 0.8em"><span style="color: #0000ff">* </span>ABACASOFT LIMITED
                    will not disclose the details provided by you on www.jewelleryonpc.com web site,
                    unless there are legal reasons to do so. &nbsp;&nbsp;</span></div>
        </div>
    </div>
</asp:Content>
