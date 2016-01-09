/////////////////////////////////////////////////////////////////////
// FileMgr.h - Implementation of FileMgr class                     //
//                                                                 //
// Application: CSE687 - Object Oriented Design-Cataloguer         //
// Platform:    Dell Inspiron, Win 8.1, Visual Studio 2013         //
// Author:      Venkata Subba Rao Cheedella, Syracuse Univesity    //
//              vcheedel@syr.edu                                   //
/////////////////////////////////////////////////////////////////////


#include "FileMgr.h"
#include "../FileSystem/FileSystemDemo/FileSystem.h"

FileMgr::FileMgr() :isRecursive(false)
{
	
}


FileMgr::~FileMgr()
{
}


//----------------< Get directory information of a given path >-----------------

Store& FileMgr::getDirectoriesList(std::string Path, Store& dirs)
{
		FileSystem::Directory::setCurrentDirectory(Path);
		std::string path = FileSystem::Directory::getCurrentDirectory();
		dirs.getDirs().insert(path);
		//std::vector<std::string> onlydirs;
		if (isRecursive == true)
			dirs = getAllDirectories(path, dirs);
	/*	else
		{
			onlydirs = FileSystem::Directory::getDirectories(path);
			for (auto viter = onlydirs.begin() + 2; viter != onlydirs.end(); viter++)
				dirs.getDirs().insert(FileSystem::Path::fileSpec(path, *viter));
		}
*/
		return dirs;	
}


//----------------------< Recursive search >---------------------------------

Store& FileMgr::getAllDirectories(std::string Path, Store& dirs)
{	
		std::vector<std::string> onlydirs;
		unsigned int lengthofdirs = dirs.getDirs().size();
		onlydirs = FileSystem::Directory::getDirectories(Path);
		onlydirs.erase(onlydirs.begin(), onlydirs.begin() + 2);
		for (auto viter = onlydirs.begin(); viter != onlydirs.end(); viter++)
		{
			FileSystem::Directory::setCurrentDirectory(Path);
			dirs.getDirs().insert(FileSystem::Path::fileSpec(FileSystem::Directory::getCurrentDirectory(), *viter));
		}
		if (dirs.getDirs().size() > lengthofdirs)
		{
			unsigned int count = 0;
			for (auto siter = dirs.getDirs().begin(); siter != dirs.getDirs().end(); siter++)
			{
				count++;
				if (count >= lengthofdirs)
					getAllDirectories(*siter, dirs);
			}
		}
		return dirs;	
}

void FileMgr::setPatterns(std::vector<std::string> patt)
{
	patterns = patt;
	/*if (patterns.at(0) == "*.txt")
		std::cout << ".txt is the first arg";
	if (patterns.at(1) == "*.cpp")
		std::cout << ".cpp is the second arg";*/
}



 //--------------< Check if user has provided recursive >--------------------

void FileMgr::setRecurrsive(std::string rec)
{
	if (rec == "/s")
		isRecursive = true;
	else
		isRecursive = false;
}

//----------------------< File Search in a directory >----------------------------

void FileMgr::filesearch(std::vector<std::string>& tempfile, std::string path)
{
	for (unsigned int i = 0; i < patterns.size(); i++)
	{
		std::vector<std::string> patternfiles;
		patternfiles = FileSystem::Directory::getFiles(path, patterns[i]);
		for (unsigned int i = 0; i < patternfiles.size(); i++)
			tempfile.push_back(patternfiles[i]);
	}
		
	/*std::cout << "\n" << path;
	for (int i = 0; i < tempfile.size(); i++)
		std::cout << "\n"<< 
		tempfile[i];*/

}

#ifdef TEST_FILEMGR
int main()
{
	FileMgr ex;
	ex.setRecurrsive("/s");	
	std::vector<std::string> paths;
	paths.push_back(".");
	Store S;
	ex.getDirectoriesList("e:/sample", S);
	for (auto diriter = S.getDirs().begin(); diriter != S.getDirs().end(); diriter++)
		std::cout << "\n" << *diriter<< "\n";
}
#endif