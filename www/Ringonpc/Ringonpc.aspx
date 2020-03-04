<%@ Page Language="C#" 
    MasterPageFile="~/AppMaster.master" 
    Title="Ringonpc Birthstone" 
    StylesheetTheme="Granite" %>

<script runat="server">

    protected void Page_Load(object sender, EventArgs e)
    {

    }
</script>

<asp:Content runat="server" ContentPlaceHolderID="mainCopy">
<script language="javascript" type="text/javascript">
// <!CDATA[

function IMG1_onclick() {

}

// ]]>
</script>

    <div class="container">
        <h2>
            <span style="font-size: 1.4em">3D Ringonpc Design Software</span></h2>
        <p>
            Ringonpc is a computer program that lets you choose from a wide range of gemstones,
            cuts, settings and materials to create your very own ring on your very own personalizied
            computer. Plus you can even change the transparency, transform it from solid to
            wire, change the backround colour etc You can have that plus much more for just
            a low low price &nbsp; &nbsp; &nbsp;&nbsp; So you can start making your very own
            jewellery today. &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
        </p>
        <p>
            <img src="../Images/ProgramView.JPG" style="width: 379px; height: 246px" />&nbsp;</p>
        <p style="text-align: right">
            <asp:HyperLink ID="hyperlink6"  runat="server" ToolTip="Read More about Ringonpc" NavigateUrl="~/Ringonpc/Design/DesignSteps.aspx">&raquo; more</asp:HyperLink>
        </p>
            
    </div>
    <div class="container">
        <p>
            <strong><span style="font-size: 1.3em; color: #444444">Birthstone jewellery on pc contains
                the following:</span></strong></p>
        <p>
            1. Gemstones<strong><span style="font-size: 1.3em; color: #444444"></span></strong></p>
        <p>
            <span style="font-size: 1.3em; color: #444444">
                <table style="font-weight: bold">
                    <tr>
                        <td>
                            Month</td>
                        <td>
                            Gemstone</td>
                    </tr>
                    <tr>
                        <td style="height: 24px">
                            January 
                        </td>
                        <td style="height: 24px">
                            Garnet</td>
                    </tr>
                    <tr>
                        <td>
                            February </td>
                        <td>
                            Amethyst</td>
                    </tr>
                    <tr>
                        <td>
                            March </td>
                        <td>
                            Aquamarine</td>
                    </tr>
                    <tr>
                        <td>
                            April 
                        </td>
                        <td>
                            Diamond</td>
                    </tr>
                    <tr>
                        <td>
                            May</td>
                        <td>
                            Emerald</td>
                    </tr>
                    <tr>
                        <td>
                            June </td>
                        <td>
                            Alexandrite</td>
                    </tr>
                    <tr>
                        <td>
                            July 
                        </td>
                        <td>
                            Ruby</td>
                    </tr>
                    <tr>
                        <td>
                            August </td>
                        <td>
                            Peridot</td>
                    </tr>
                    <tr>
                        <td>
                            September </td>
                        <td>
                            Blue Sapphire</td>
                    </tr>
                    <tr>
                        <td>
                            October </td>
                        <td>
                            Tourmaline (Rubellite)</td>
                    </tr>
                    <tr>
                        <td>
                            November </td>
                        <td>
                            Citrine</td>
                    </tr>
                    <tr>
                        <td>
                            December </td>
                        <td>
                            Blue Topaz</td>
                    </tr>
                </table>
            </span>
        </p>
        <p style="font-weight: bold">
            Including &nbsp; &nbsp;&nbsp;
        </p>
        <p>
            &nbsp;a wide variety of Metals, Ring Bands and Settings!</p>
        <p>
            &nbsp;</p>
        <p>
            &nbsp;</p>
        <p style="text-align: right">
            <asp:HyperLink ID="hyperlink1"  runat="server" ToolTip="Read More about Ringonpc" NavigateUrl="~/Ringonpc/Design/DesignSteps.aspx">&raquo; more</asp:HyperLink>
        </p>
    </div>
</asp:Content>
