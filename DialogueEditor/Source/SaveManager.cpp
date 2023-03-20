#include "SaveManager.h"

void SaveManager::OpenFile(std::string path)
{
	std::ifstream inf;
	inf.open(path);
	if (inf.is_open())
	{
		while (!inf.eof())
		{
			std::string str;
			std::getline(inf, str);
			if (str != "")
				ReadLine(str);
		}
	}
	else std::cout << "Couldn't open " << path << std::endl;
}

void SaveManager::ReadLine(std::string line)
{
	std::cout << line << std::endl;
}
