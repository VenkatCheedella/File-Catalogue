#ifndef DISPLAY_H
#define DISPLAY_H

/////////////////////////////////////////////////////////////////////
// Display.h - Display the results to console                      //
//                                                                 //
// Application: CSE687 - Object Oriented Design-Cataloguer         //
// Platform:    Dell Inspiron, Win 8.1, Visual Studio 2013         //
// Author:      Venkata Subba Rao Cheedella, Syracuse Univesity    //
//              vcheedel@syr.edu                                   //
/////////////////////////////////////////////////////////////////////
/*
Purpose : Display the results of the given request.
*/


///////////////////////////////////////////////////////////////
//  Build Process                                            //
///////////////////////////////////////////////////////////////
//  Required files:                                          //
//    FileSystem.h, FileSystem.cpp,Store.h,Store.cpp,		 //
//	  Display.h and Display.cpp                              //
//                                                           //
//                                                           //
///////////////////////////////////////////////////////////////


/*
Maintenance History
==========================

	ver 1.0  : 11 feb 2015
	- First Release


*/


#include <iostream>
#include "../Store/Store.h"
#include <vector>
#include <set>


class Display
{
public:
	Display();
	~Display();
	static void displayCatalogue(Store& S);
	static void displayduplicates(Store& S);
	static void displayFileNames(std::vector<std::map<key, value>::iterator>& miters);	
};

#endif

