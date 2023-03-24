#pragma once
#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include "NodesList.h"

class Editor;
class SaveManager
{
public:
	SaveManager(Editor* editor)
	{
		this->editor = editor;
	};
	~SaveManager() {};

	void OpenFile(std::string path);
	void ReadLine(std::string line);

private:
	Editor* editor;
	std::map<std::string, NodeType> nodeMap = {
		{"DlgStart", Start},
		{"DlgEnd", End},
		{"PrgQuest", ProgrQst},
		{"GiveMny", GiveMny},
	};
};

