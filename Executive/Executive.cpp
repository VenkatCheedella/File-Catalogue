#include <iostream>
#include <string>
/////////////////////////////////////////////////////////////////////
// Executive.cpp - Entry point of the application                  //
//                                                                 //
// Application: CSE687 - Object Oriented Design-Cataloguer         //
// Platform:    Dell Inspiron, Win 8.1, Visual Studio 2013         //
// Author:      Venkata Subba Rao Cheedella, Syracuse Univesity    //
//              vcheedel@syr.edu                                   //
/////////////////////////////////////////////////////////////////////

/*


Required Files
======================
Executive, Display.h, Display.cpp. FileMgr.h, FileMgr.cpp, Store.h, Store.cpp, FileSystem.h,
FileSystem.cpp, TestCatalogue.h, TestCatalogue.cpp, TextSearch.h and TextSearch.cpp.


Maintenance History
======================

	ver 1.0  : 11 feb 2015
	- First Release

*/

#include "../TestCatalogue/TestCatalogue.h"
#include "../Display/Display.h"
#include "../FileMgr/FileMgr.h"
#include "../FileSystem/FileSystemDemo/FileSystem.h"
#include "../Store/Store.h"


int main(int argc, char* argv[])
{		
		std::vector<std::string> cmdargs;
		for (auto i = 1; i < argc; i++)
			cmdargs.push_back(argv[i]);		
		TestCatalogue testc(cmdargs);
		testc.controller();
		/*std::cout << "Exception occured in the commmand line argument. Please enter the data in the given pattern";
		std::cout << "Ex:" << "E: / sample" << "*.cpp" << " / s" << " / d" << "/finclude" << "\n";	*/	
}