# demo 
RingonpcbirthstoneDemoSetup.msi </br>
https://github.com/teocot/www-jewelleryonpc-com/raw/master/RingonpcbirthstoneDemoSetup.msi</br>

# www-jewelleryonpc-com
website for the ringonpcbirthstone software, some code extracts</br>

# cpp-src
some cpp source code which is part of the birthstone software<br/>
it shows libs ans tests of those libs, grouping of libraries <br/><br/>
I use <br/>
win32 exeption handler for exceptions to avoid dr watson or crashes<br/>
smart pointers to manage memory <br/>
cppunit for unit tests<br/>
classes wrap the opengl functions and enums<br/>

<br/>
Exceptions handling<br/>
	__try<br/>
	{<br/>
		m_descriptionControls.importFromFile(strDescriptionFileName);<br/>
	}<br/>
	__except(EXCEPTION_EXECUTE_HANDLER)<br/>
	{<br/>
		Util::displayException(GetExceptionCode(), TEXT(__FILE__), __LINE__);<br/>
		return_value = false;<br/>
		goto cleanup;<br/>
	}<br/>
  
 
