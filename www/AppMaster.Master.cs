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

namespace jewelleryonpc
{
    public partial class AppMaster : System.Web.UI.MasterPage
    {
        /// <summary>
        /// Event handler that highlights the top level menu section for all
        /// sections and pages below it.
        /// </summary>
        protected void MainMenu_MenuItemDataBound(Object sender, MenuEventArgs e)
        {
            if (mainmenu.SelectedItem == null)
            {
                if (IsNodeAncestor((SiteMapNode)e.Item.DataItem, SiteMap.CurrentNode))
                    e.Item.Selected = true;
            }
        }

        /// <summary>
        /// Determines if a <see cref="System.Web.SiteMapNode"/> is the ancestor of a second one.
        /// </summary>
        /// <param name="ancestor">The <see cref="System.Web.SiteMapNode"/> in question.</param>
        /// <param name="child">A <see cref="System.Web.SiteMapNode"/> which may or may not be 
        /// the <paramref name="ancestor"/>'s child.</param>
        /// <returns><c>true</c>, if the two nodes are related, <c>false</c> otherwise.</returns>
        private bool IsNodeAncestor(SiteMapNode ancestor, SiteMapNode child)
        {
            bool result = false;

            if (ancestor.ChildNodes != null && ancestor.ChildNodes.Contains(child))
                return true;
            else
            {
                if (child.ParentNode != null && ancestor != child.RootNode)
                {
                    return IsNodeAncestor(ancestor, child.ParentNode);
                }
            }

            return result;
        }
    }
}