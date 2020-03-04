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
//so I will make it instantiable. each request creates
//an obejct of it and use it.
public class Meshes
{
    private int m_noFiles = 0;
	public Meshes()
	{
        init();
	}

    public void init()
    {
        m_noFiles = int.Parse(readNoMeshFilesFromDatabase());
    }

    public string readNoMeshFilesFromDatabase()
    {
        string returnValue = null;
        returnValue = Database.readFromDataBase("SELECT COUNT(*) FROM MESH");

        return returnValue;
    }

    public int getNoFiles()
    {
        return m_noFiles;
    }

    public string getMeshFileData(int index, string strKey)
    {
        if (index < 0 || index > m_noFiles)
        {
            return "No file with index = " + index;
        }

        string strStatement = "SELECT DATA FROM MESH WHERE ID = " + index;
        string returnValue = null;
        returnValue = Database.readMeshFromDataBase(strStatement);

        model.Encryption enc = new model.Encryption();
        returnValue = enc.encryptString(returnValue,strKey );

        return returnValue;
    }

    public string getMeshFileName(int index)
    {
        if (index < 0 || index > m_noFiles)
        {
            return "No file with index = " + index;
        }

        string strStatement = "SELECT FILE_NAME FROM MESH WHERE ID = " + index;
        string returnValue = null;
        returnValue = Database.readFromDataBase(strStatement);

        return returnValue;
    }


    public string[] getAllFiles(string strKey)
    {
        string [] strFiles = new  string[m_noFiles];
        for (int i = 0; i < m_noFiles; i++)
        {
            strFiles[i] = getMeshFileData(i, strKey);            
        }
        return strFiles;
    }
}
