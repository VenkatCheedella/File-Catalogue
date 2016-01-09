#ifndef FILEMGR_H
#define FILEMGR_H


/////////////////////////////////////////////////////////////////////
// FileMgr.h - To retrive Directory and files                      //
//                                                                 //
// Application: CSE687 - Object Oriented Design-Cataloguer         //
// Platform:    Dell Inspiron, Win 8.1, Visual Studio 2013         //
// Author:      Venkata Subba Rao Cheedella, Syracuse Univesity    //
//              vcheedel@syr.edu                                   //
/////////////////////////////////////////////////////////////////////


/*

Retrieves directories (recursive scan) for a given 
directory with the help of fileSystem. Retrives the files for a given
pattern in a directory.


Required Files
======================
FileMgr.h, FileMgr.cpp, Store.h, Store.cpp, FileSystem.h,
FileSystem.cpp.

*/

/*

Maintenance history
===================

ver 1.0  : 11 feb 2015
- First Release


*/


#include <iostream>
#include <string>
#include <vector>
#include "../Store/Store.h"

using dirstore = std::vector<std::string>;


class FileMgr
{
public:
	FileMgr();
	~FileMgr();
	Store& getDirectoriesList(std::string Path, Store& dirs);
	void setPatterns(std::vector<std::string> patt);
	void setRecurrsive(std::string rec);
	void filesearch(std::vector<std::string>& tempfile, std::string path);

private:
	std::vector<std::string> patterns;
	bool isRecursive;
	Store& getAllDirectories(std::string Path, Store& dirs);
};


#endif
