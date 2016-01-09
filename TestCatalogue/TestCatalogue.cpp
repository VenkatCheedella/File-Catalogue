/////////////////////////////////////////////////////////////////////
// TestCatalogue.cpp - Implementation of Controller class          //
//                                                                 //
// Application: CSE687 - Object Oriented Design-Cataloguer         //
// Platform:    Dell Inspiron, Win 8.1, Visual Studio 2013         //
// Author:      Venkata Subba Rao Cheedella, Syracuse Univesity    //
//              vcheedel@syr.edu                                   //
/////////////////////////////////////////////////////////////////////

#include "TestCatalogue.h"
#include <iostream>
#include "../Display/Display.h"
#include "../Store/Store.h"
#include "../FileMgr/FileMgr.h"
#include "../FileSystem/FileSystemDemo/FileSystem.h"
#include "../TextSearch/TextSearch.h"


using value = std::list<std::set<std::string>::iterator>;

TestCatalogue::TestCatalogue(std::vector<std::string> cmdargs) : arguments(cmdargs)
{

}

TestCatalogue::~TestCatalogue()
{
}

//--------------< Decode the /f<text> option of cmd line >--------------

std::string TestCatalogue::getText(std::string arg)
{
	std::string fsearch;
	fsearch = arg.substr(0, 2);
	if (fsearch == "/f")
	{
		text = arg.substr(2);
	}
	return text;
}

//--------------------< Decode the patterns of a file search >----------------------------------

std::vector<std::string> TestCatalogue::getPatterns(std::string arg)
{	
		patterns.clear();
		std::string pat = arg;
		if (arg == "")
			patterns.push_back("*.*");
		while (pat.find_first_of(" ") != std::string::npos)
		{
			int pos = pat.find_first_of(" ");
			patterns.push_back(pat.substr(0, pos));
			pat = pat.substr(pos + 1);
		}
		if (arg != "")
		patterns.push_back(pat);
		return patterns;			
		std::cout << "\n" <<"Please enter the valid string";
}

//------------------< Provide an option to search after the catalogue is created >---------------

void TestCatalogue::recSearch(TextSearch& txtSearch)
{
	std::string arg;
	std::vector<std::string> args;
	while (true)
	{
		std::cout << "\n\n" << "Enter the text to search : " << "\t";
		std::string searchText;
		std::getline(std::cin, searchText);
		if (searchText == "")
			break;
		else
		{		
			std::cout << "\n" << "Enter the pattern to search :" << "\t";
			std::getline(std::cin, arg);
			std::vector<std::map<key, value>::iterator> recmapiters;
			txtSearch.getFiles(getPatterns(arg), recmapiters);
			if (searchText != "")										
					txtSearch.searchText(recmapiters, searchText);			
				/*else
				{
				std::cout << "\n" <<"\n\n" << "Please enter valid arguments";
				std::cout << "\n" << "For ex: Enter the text to search : class Display " ;
				std::cout << "\n" << "For ex: Enter the pattern to search : *.cpp *.txt ";
				}	*/			
		}
	}	
}

//--------------------< Controls the data flow and process of the cataloguer >-----------------------------

void TestCatalogue::controller()
{		
		Store store;
		createCatalogue(store);
		for (auto argsiter = arguments.begin(); argsiter != arguments.end(); argsiter++)
		{
			if (*argsiter == "/d")
				Display::displayduplicates(store);
		}		

		if (arguments[2] == "" && arguments[3] == "" && arguments[4] == "")
		{
			std::cout << "\n\n" << store.getMap().size() << " files found in the given directory" << "\n";
			Display::displayCatalogue(store);
		}

		TextSearch txtSearch(store);		
		std::vector<std::map<key, value>::iterator> miterators;
		for (auto miter = store.getMap().begin(); miter != store.getMap().end(); miter++)
			miterators.push_back(miter);

		if (arguments[4] != "")
		{
			std::string temptext = getText(arguments[4]);
			//std::cout << temptext;
			if (temptext != "")
				txtSearch.searchText(miterators, temptext);
			else
				std::cout << "\n\n" << "Text is not provided";
		}			
		recSearch(txtSearch);			
}

//------------------------< Creation of cataloguer >---------------------------

void TestCatalogue::createCatalogue(Store& store)
{	
		FileMgr fm;
		for (auto argsiter = arguments.begin(); argsiter != arguments.end(); argsiter++)
		{
			if (*argsiter == "/s")
				fm.setRecurrsive("/s");
		}
		std::vector<std::string> patts = getPatterns(arguments[1]);
		fm.setPatterns(patts);	
		if (arguments[0] == "")
			arguments[0] == ".";
		fm.getDirectoriesList(arguments[0], store);		
		createMap(store, fm);			
	
}


//-------------------< Creation of Map >-----------------------------------

void TestCatalogue::createMap(Store& str, FileMgr fmgr)
{	
		for (auto diter = str.getDirs().begin(); diter != str.getDirs().end(); diter++)
		{
			std::vector<std::string> tempfile;
			fmgr.filesearch(tempfile, *diter);
			for (unsigned int i = 0; i < tempfile.size(); i++)
			{
				int keyexist = 0;
				for (auto mapiter = str.getMap().begin(); mapiter != str.getMap().end(); mapiter++)
				{
					if (mapiter->first == tempfile[i])
					{
						mapiter->second.push_back(diter);
						keyexist++;
					}
				}
				if (keyexist == 0)
				{
					value dlist;
					dlist.push_back(diter);
					std::string tempstr = tempfile[i];
					str.getMap()[tempstr] = dlist;
				}
			}
			tempfile.clear();
		}		
}

#ifdef TEST_TESTCATALOGUE

int main()
{	
	std::vector<std::string> sampleargs;
	sampleargs.push_back(".");
	sampleargs.push_back("*.*");
	sampleargs.push_back("/s");
	sampleargs.push_back("/d");
	sampleargs.push_back("/finclude");
	TestCatalogue testc(sampleargs);
	testc.controller();

}
#endif