#include "Folder.h"
#include <iostream>
using namespace std;

Folder::Folder(std::string name) : _name(name)
{
}

Folder::Folder()
{
}

Folder::~Folder()
{
}

std::vector<std::string> Folder::ListFiles()
{
	std::vector<std::string> list;
	for (auto file : _files)
	{
		list.push_back(file->getName());
	}
	return list;
}



std::string Folder::ListContents()
{
	std::string output = "\n";
	for (auto folder : _folders) 
	{
		output += "\\" + folder->getName() + "\n";
	}
	for (auto file : _files) 
	{
		output += file->getName() + "\n";		
	}
	return output;
}



void Folder::AddFile(std::shared_ptr<File> newFile)
{
	_files.push_back(newFile);
}



void Folder::AddFolder(std::shared_ptr<Folder> newFolder)
{
	_folders.push_back(newFolder);
}



std::shared_ptr<Folder> Folder::FindFolder(std::string name)
{
	for(auto folder : _folders)
	{
		if (folder->getName() == name)
		{
			return folder;
		}
	}
	return nullptr;
}

std::string Folder::searchForFile(std::string name)
{
    std::string output;
    
    for(auto file : _files)
    {
        if(file->getName() == name && _files.size() != 0)
        {
            output += "\nFile Found: " + name + "\n" + "Located in folder: " + getName() + "\n";
            
            return output;
        }
    }
    
    
    for (auto folder : _folders)
    {
        auto file = folder->searchForFile(name);
        if(file != "File Not Found")
        {
            return file;
        }
    }
    
    output += "File Not Found";
    return output;
    
    
}


//Loop/Iterate this folder's files
//If you find a file with the passed name, return it

//Loop/Iterate this folder's folders
//Search(each folder in the loop)
//Otherwise return nullptr
