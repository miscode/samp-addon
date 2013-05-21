#pragma once

#include "fs.h"





addonFS::addonFS()
{
	addonDebug("FS constructor called");
}



addonFS::~addonFS()
{
	addonDebug("FS deconstructor called");
}



std::vector<std::string> addonFS::Dir(std::string folder)
{
	std::vector<std::string> ret;

	this->directory = opendir(folder.c_str());

	if(this->directory != NULL)
	{
		while(this->entry = readdir(this->directory))
		{
			ret.push_back(this->entry->d_name);                
		}

		closedir(this->directory);

		return ret;
	}

	return ret;
}