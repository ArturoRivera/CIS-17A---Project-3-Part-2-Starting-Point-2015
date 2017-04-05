#include "Folder.h"

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

std::shared_ptr<File> Folder::searchForFile(std::string name)
{
	for (auto folder : _folders)
	{
		if (file->getName() == name)
		{
			return file;
		}
	}


	for (auto folder : _folders)
	{
		auto file = folder->searchForFile(name);
		if (file != nullptr)
		{
			return file;
		}

		return nullptr;

	}
}


//Loop/Iterate this folder's files
//If you find a file with the passed name, return it

//Loop/Iterate this folder's folders
//Search(each folder in the loop)
//Otherwise return nullptr
for (int 1 = 0; i < _folders.size(); i++)
	auto folder = _folders[i];