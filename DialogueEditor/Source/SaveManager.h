#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class SaveManager
{
public:
	SaveManager() {};
	~SaveManager() {};

	void OpenFile(std::string path);
	void ReadLine(std::string line);
};

