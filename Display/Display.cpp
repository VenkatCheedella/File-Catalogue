/////////////////////////////////////////////////////////////////////
// Display.h - Implementation of display class                     //
//                                                                 //
// Application: CSE687 - Object Oriented Design-Cataloguer         //
// Platform:    Dell Inspiron, Win 8.1, Visual Studio 2013         //
// Author:      Venkata Subba Rao Cheedella, Syracuse Univesity    //
//              vcheedel@syr.edu                                   //
/////////////////////////////////////////////////////////////////////


#include "Display.h"
#include <iostream>
#include <string>
#include "../Store/Store.h"
#include "../FileSystem/FileSystemDemo/FileSystem.h"

Display::Display()
{
}


Display::~Display()
{
}
//--------------< Display filenames of a pattern>----------------------

void Display::displayFileNames(std::vector<std::map<key, value>::iterator>& miters)
{	
	for (unsigned int i = 0; i < miters.size(); i++)
	{
		for (auto liter = miters[i]->second.begin(); liter != miters[i]->second.end(); liter++)
		{
			std::cout << "\n" << FileSystem::Path::fileSpec(**liter, miters[i]->first);				
		}		
	}		
}


//----------------< Display Cataloguer content (Map) >-------------

void Display::displayCatalogue(Store& S)
{
	std::cout << "\n" << "Directory :";
	std::cout << "\n" << "== == == == == == ==" ;
	for (auto siter = S.getDirs().begin(); siter != S.getDirs().end(); siter++)
		std::cout << "\n" << *siter;
	std::cout << "\n\n" << "List of files and their locations " << "\n";
	std::cout << "========================================";
	for (auto miter = S.getMap().begin(); miter != S.getMap().end(); miter++)
	{

		std::cout << "\n\n" << miter->first << ":";
		for (auto liter = miter->second.begin(); liter != miter->second.end(); liter++)
			std::cout << "\n" << *(*liter);
	}

}

//--------------------------< Display duplicate file names >------------------------------------------

void  Display::displayduplicates(Store& S)
{
	std::cout << "\n\n" << "Duplicate files information";
	std::cout << "\n"<<"=================================";
	int count = 0;
	for (auto miter = S.getMap().begin(); miter != S.getMap().end(); miter++)
	{
		if (miter->second.size() > 1)
		{
			std::cout << "\n\n" << "FileName :" << "\t" << miter->first << "\t and it present in the following paths" <<"\n";
			for (auto liter = miter->second.begin(); liter != miter->second.end(); liter++)
				std::cout << "\n\n" << **liter;
			count++;
		}

	}
	if (count == 0)
		std::cout << "\n" << "No duplicate files are present";
}

#ifdef TEST_DISPLAY
int main()
{
	// The pacakge is  display  to print on console, no other functionality is defined.
}

#endif