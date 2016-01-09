/////////////////////////////////////////////////////////////////////
// Store.h - Implementation of store class                         //
//                                                                 //
// Application: CSE687 - Object Oriented Design-Cataloguer         //
// Platform:    Dell Inspiron, Win 8.1, Visual Studio 2013         //
// Author:      Venkata Subba Rao Cheedella, Syracuse Univesity    //
//              vcheedel@syr.edu                                   //
/////////////////////////////////////////////////////////////////////



#include "Store.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>


Store::Store()
{
}


Store::~Store()
{
}


std::set<std::string>& Store::getDirs()
{
	return listOfDirs;

}
std::map<key, value>& Store::getMap()
{
	return catalogue;
}


#ifdef TEST_STORE
int main()
{
	Store s;	
	std::set<std::string> vstring;
	vstring.insert(".");
	vstring.insert("e:/sample");
	int count = 0;	
	value v1;
	auto viter = vstring.begin();
	v1.push_back(viter);
	s.getMap()["venk1.txt"] = v1;
	value v2;
	v1.push_back(viter++);
	s.getMap()["venkat1"] = v2;

	std::cout << "\n" <<"Filenames : ";
	for (auto miter = s.getMap().begin(); miter != s.getMap().end(); miter++)
	{
		std::cout << "\n" <<miter->first;
	}
	std::cout << "\n" << "Paths : ";
	for (auto siter = vstring.begin(); siter != vstring.end(); siter++)
	{
		std::cout << "\n" << *siter;
	}
}
#endif
