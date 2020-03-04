using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

namespace license
{
    public class License
    {
        char[] asciiSet =
				        {	'1','2','3','4','5','6','7','8','9','0',
					        'A','B','C','D','E','F','G','H','I','J',
					        '1','2','3','4','5','6','7','8','9','0',
					        'K','L','M','N','O','P','Q','R','S','T',
					        '1','2','3','4','5','6','7','8','9','0',
					        'U','V','W','X','Y','Z','A','B','C','D',
					        'E','F','G','H','I','J','K','L','M','N',
					        '1','2','3','4','5','6','7','8','9','0',
					        'O','P','Q','R','S','T','U','V','W','X',
					        'Y','Z','1','2','3','4','5','6','7','8',
					        '9','0'};
        public string s_strUserName;
        public string s_strProductID = "1234567890";
        public string s_strSoftwareKey = "aaaa-aaaa-aaaa-aaaa";
        // --------------------------------------------
        public License()
        {
            s_strProductID = this.generateProduct();
            s_strSoftwareKey = this.generateProductKey(s_strProductID);
        }
        // ----------------------------------------------------------------------------
        bool checkKey()
        {
            if ("" == s_strProductID || "" == s_strSoftwareKey)
            {
                return false;
            }
            if (s_strProductID.Length != 10)
            {
                return false;
            }
            long time = long.Parse(s_strProductID);
            if (time < 1163409693)//nov 2006
            {
                return false;
            }
            string strTime;
            strTime = currentTime();
            if (time > long.Parse(strTime))
            {
                return false;
            }

            string strX = getXString(s_strSoftwareKey);
            string strY = getYString(s_strSoftwareKey);

            int factor = sumElementsUntilSumIsOneDigit(s_strProductID);
            int sumX = sumElements(strX);
            if ((sumX % factor) != 0)
            {
                return false;
            }
            int sumY = sumElements(strY);
            if (factor < 5)
            {
                factor += 5;
            }
            else if (factor == 5)
            {
                ;
            }
            else// factor > 5
            {
                factor = factor - 5;
            }
            if ((sumY % factor) != 0)
            {
                return false;
            }

            return true;
        }
        /** ---------------------------------------------------------------------------
         * 1. generate 2. test 3. setparam 4. return
         * returns a key based on the product
         * ----------------------------------------------------------------------------
         */
        string generateProductKey(string strProduct)
        {
            Random r = new Random(0);
//            int value = 0;
            string strKey = "";

            string strXPart = createXString(strProduct);
            string strYPart = createYString(strProduct);

            strKey += (strXPart.Substring(0, 1));
            strKey += (strXPart.Substring(1, 1));
            strKey += (strXPart.Substring(2, 1));
            strKey += (strXPart.Substring(3, 1));
            strKey += "-";
            strKey += (strYPart.Substring(0, 1));
            strKey += (strYPart.Substring(1, 1));
            strKey += (strYPart.Substring(2, 1));
            strKey += (strYPart.Substring(3, 1));
            strKey += "-";
            strKey += (strXPart.Substring(4, 1));
            strKey += (strXPart.Substring(5, 1));
            strKey += (strXPart.Substring(6, 1));
            strKey += (strXPart.Substring(7, 1));
            strKey += "-";
            strKey += (strYPart.Substring(4, 1));
            strKey += (strYPart.Substring(5, 1));
            strKey += (strYPart.Substring(6, 1));
            strKey += (strYPart.Substring(7, 1));

            return strKey;
        }
        // ----------------------------------------------------------------------------
        string currentTime()
        {
            TimeSpan t = (DateTime.UtcNow - new DateTime(1970, 1, 1));
            long timestamp = (long)t.TotalSeconds;
            string strTime = "";
            strTime += timestamp;
            return strTime;
        }
        // ----------------------------------------------------------------------------
        long currentTimeLong()
        {
            TimeSpan t = (DateTime.UtcNow - new DateTime(1970, 1, 1));
            long timestamp = (long)t.TotalSeconds;
            return timestamp;
        }
        // ----------------------------------------------------------------------------
        string generateProduct()
        {
            return currentTime();
        }
        // ----------------------------------------------------------------------------
        int sumElements(string strElements)
    {
	    int sum = 0;
        char[] cElements = strElements.ToCharArray();
	    for (int i=0; i < (int) cElements.Length; i++)
	    {
		    int value = 0;
		    string  strValue = "";
    		
		    if(!Char.IsDigit(cElements[i]))
		    {
			    value = cElements[i] ;
		    }
		    else
		    {
			    strValue += cElements[i];
			    string  one = strValue.Substring(0,1);
			    value = int.Parse(one);
		    }

		    sum += value;
	    }	
	    return sum;
    }
        // ----------------------------------------------------------------------------
        int sumElementsUntilSumIsOneDigit(string strValue)
        {
            int sum = 0;
            sum = sumElements(strValue);
            while (sum > 9)
            {
                string strCSum = "";
                strCSum += sum;
                sum = sumElements(strCSum);
            }
            return sum;
        }
        // ----------------------------------------------------------------------------
        int getAsciiSetIndex(int value)
        {
            for (int i = 0; i < 101; i++)
            {
                if (Char.IsDigit(asciiSet[i]))
                {
                    string strValue = "";
                    strValue += asciiSet[i];
                    int charValue = int.Parse(strValue);
                    if (charValue == value)
                    {
                        return i;
                    }
                    continue;
                }

                if (asciiSet[i] == value)
                {
                    return i;
                }
            }
            return -1;
        }
        // ----------------------------------------------------------------------------
        string getLetterFromAsciiSet(int index)
        {
            if (index < 0 || index > 101)
            {
                return "";
            }

            string letter = "";
            letter += asciiSet[index];
            return letter;
        }
        // ----------------------------------------------------------------------------
        string getXString(string strKey)
        {
            string strXString = "";

            strXString += (strKey.Substring(0, 1));
            strXString += (strKey.Substring(1, 1));
            strXString += (strKey.Substring(2, 1));
            strXString += (strKey.Substring(3, 1));
            strXString += (strKey.Substring(10, 1));
            strXString += (strKey.Substring(11, 1));
            strXString += (strKey.Substring(12, 1));
            strXString += (strKey.Substring(13, 1));

            return strXString;
        }
        // ----------------------------------------------------------------------------
        string getYString(string strKey)
        {
            string strYString = "";

            strYString += (strKey.Substring(5, 1));
            strYString += (strKey.Substring(6, 1));
            strYString += (strKey.Substring(7, 1));
            strYString += (strKey.Substring(8, 1));
            strYString += (strKey.Substring(15, 1));
            strYString += (strKey.Substring(16, 1));
            strYString += (strKey.Substring(17, 1));
            strYString += (strKey.Substring(18, 1));

            return strYString;
        }
        // ----------------------------------------------------------------------------
        string createXString(string strProduct)
        {
            string strXString = "";
            Random r = new Random((int)currentTimeLong());
            int value = 0;
            for (int i = 0; i < 7; i++)
            {
                value = r.Next(0, 101);
                strXString += asciiSet[value];
            }

            int factor = sumElementsUntilSumIsOneDigit(strProduct);
            if (factor > 9 || factor < 1)
            {
                Console.WriteLine("createXString invalid factor");
                return "";
            }

            strXString = prepareString(strXString, factor);
            return strXString;
        }
        // ----------------------------------------------------------------------------
        string createYString(string strProduct)
        {
            string strYString = "";
            Random r = new Random();
            int value = 0;
            for (int i = 0; i < 7; i++)
            {
                value = r.Next(0, 101);
                strYString += asciiSet[value];
            }

            int factor = sumElementsUntilSumIsOneDigit(strProduct);
            if (factor > 9 || factor < 1)
            {
                Console.WriteLine("createYString invalid factor");
                return "";
            }
            if (factor < 5)
            {
                factor += 5;
            }
            else if (factor == 5)
            {
                ;
            }
            else// factor > 5
            {
                factor = factor - 5;
            }
            strYString = prepareString(strYString, factor);
            return strYString;
        }
        // ----------------------------------------------------------------------------
        string prepareString(string strInput, int factor)
        {
	        if(factor > 9 || factor <1)
	        {
		        //invalid, should be between 1-9, inclusive
		        Console.WriteLine( "Invalid factor") ;
		        return "";
	        }

	        string  strPrepared = strInput;
	        int sum = 0;
	        int reminder;
	        
	        sum = sumElements(strPrepared);
	        reminder = sum % factor;
	        int suffix = factor - reminder;

	        strPrepared += suffix;

	        //this string  now divides factor.
	        //let's test it
	        return strPrepared;
        }
        // ----------------------------------------------------------------------------
        void init()
        {
            s_strUserName = ("");
            s_strProductID = ("");
            s_strSoftwareKey = ("");
        }

    }
}