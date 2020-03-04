using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using data;
//static class, no public constructor
//we should worry about concurency, however.
//so I will make it instantiable.
public class Cuts
{
    private int m_noFiles = 0;
	public Cuts()
	{
        init();
	}

    public void init()
    {
        m_noFiles = int.Parse(readNoCutFilesFromDatabase());
    }

    public string readNoCutFilesFromDatabase()
    {
        string returnValue = null;
        returnValue = Database.readFromDataBase("SELECT COUNT(*) FROM CUT");

        return returnValue;
    }

    public int getNoFiles()
    {
        return m_noFiles;
    }

    public string getCutFileContent(int index, string strKey)
    {
        if (index < 0 || index > m_noFiles)
        {
            return "No file with index = " + index;
        }

        string strStatement = "SELECT CONTENT FROM CUT WHERE ID = " + index;
        string returnValue = null;
        returnValue = Database.readFromDataBase(strStatement);

        model.Encryption enc = new model.Encryption();
        returnValue = enc.encryptString(returnValue,strKey );

        return returnValue;
    }

    public string getCutFileName(int index)
    {
        if (index < 0 || index > m_noFiles)
        {
            return "No file with index = " + index;
        }

        string strStatement = "SELECT FILE_NAME FROM CUT WHERE ID = " + index;
        string returnValue = null;
        returnValue = Database.readFromDataBase(strStatement);

        return returnValue;
    }


    public string[] getAllFiles(string strKey)
    {
        string [] strFiles = new  string[m_noFiles];
        for (int i = 0; i < m_noFiles; i++)
        {
            strFiles[i] = getCutFileContent(i, strKey);            
        }
        return strFiles;
    }
}
