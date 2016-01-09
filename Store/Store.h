#ifndef STORE_H
#define STORE_H

/////////////////////////////////////////////////////////////////////
// Store.h - Storage class                                       //
//                                                                 //
// Application: CSE687 - Object Oriented Design-Cataloguer         //
// Platform:    Dell Inspiron, Win 8.1, Visual Studio 2013         //
// Author:      Venkata Subba Rao Cheedella, Syracuse Univesity    //
//              vcheedel@syr.edu                                   //
/////////////////////////////////////////////////////////////////////

/*
Here we define a containers, Map and Set to store the directories and files.


Required Files
======================
Display.h, Display.cpp. FileMgr.h, FileMgr.cpp, Store.h, Store.cpp, FileSystem.h,
FileSystem.cpp, TestCatalogue.h, TestCatalogue.cpp, TextSearch.h and TextSearch.cpp.

*/

/*

Maintenance history
=======================

	ver 1.0  : 11 feb 2015
	- First Release

*/


#include <iostream>
#include <set>
#include <map>
#include <list>
#include <set>

using key = std::string;
//using ref = std::set<std::string>::iterator;
using value = std::list<std::set<std::string>::iterator>;

class Store
{
public:
	Store();
	~Store();	
	std::set<std::string>& getDirs();
	std::map<key, value>& getMap();
		
private:
	std::set<std::string> listOfDirs;
	std::map<key, value> catalogue;	
};


#endif
