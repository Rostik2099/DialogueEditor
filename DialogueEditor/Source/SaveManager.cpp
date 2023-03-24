#include "SaveManager.h"
#include "Editor.h"

void SaveManager::OpenFile(std::string path)
{
	std::ifstream inf;
	inf.open(path);
	if (inf.is_open())
	{
		editor->GetDlgEditor()->Clear();
		while (!inf.eof())
		{
			std::string str;
			std::getline(inf, str);
			if (str != "")
				ReadLine(str);
		}
		editor->GetDlgEditor()->OnFileOpened();
	}
	else std::cout << "Couldn't open " << path << std::endl;
}

void SaveManager::ReadLine(std::string line)
{
	if (line[0] == '$')
	{
		size_t eqPos = line.find_first_of('=') + 1;
		std::cout << "Filename: " << line.substr(eqPos) << std::endl;
	}
	if (line[0] == '#')
	{
		std::string nodeType;
		size_t eqPos = line.find_first_of('=');
		nodeType = line.substr(1, eqPos - 1);

		size_t comPos = line.find_first_of(',');
		size_t skPos = line.find_first_of(')');
		std::string sposX, sposY;
		sposX = line.substr(eqPos + 2, comPos - eqPos - 2);
		sposY = line.substr(comPos + 1, skPos - comPos - 1);
		ImVec2 nodePos = ImVec2(std::stof(sposX), std::stof(sposY));
		editor->GetDlgEditor()->SpawnNode(nodeMap[nodeType], nodePos);
	}
}
