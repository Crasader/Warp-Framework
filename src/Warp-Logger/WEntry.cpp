// � 2019 NIREX ALL RIGHTS RESERVED

#include "WFile.h"
#include "WString.h"
#include "WWin.h"

HANDLE hConsole;

// Pass			10	: 0
// Info			8	: 1
// Debug		15	: 2
// Message		15	: 3
// Warning		14	: 4
// Trace		9	: 5 
// Error		12	: 6
// Fatal		207	: 7

void XPrint(std::string text, WORD color)
{
	SetConsoleTextAttribute(hConsole, color);
	std::cout << text;
	SetConsoleTextAttribute(hConsole, 15);
	return;
}

bool Parse(std::string message)
{
	WString parser;
	std::vector<std::string> vecS = parser.Split(message, "::");

	if (vecS.size() < 2)
		return false;
	int level = std::stoi(vecS[1]);

	switch (level)
	{
	case 0:
	{
		XPrint("[", 15);
		XPrint("P", 10);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 10);
		break;
	}
	case 1:
	{
		XPrint("[", 15);
		XPrint("I", 8);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 8);
		break;
	}
	case 2:
	{
		XPrint("[", 15);
		XPrint("D", 15);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 15);
		break;
	}
	case 3:
	{
		XPrint("[", 15);
		XPrint("M", 15);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 15);
		break;
	}
	case 4:
	{
		XPrint("[", 15);
		XPrint("W", 14);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 14);
		break;
	}
	case 5:
	{
		XPrint("[", 15);
		XPrint("T", 9);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 9);
		break;
	}
	case 6:
	{
		XPrint("[", 15);
		XPrint("E", 12);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 12);
		break;
	}
	case 7:
	{
		XPrint("[", 15);
		XPrint("F", 207);
		XPrint("]", 15);
		XPrint(" [" + vecS[0] + "] ", 15);
		XPrint(vecS[2] + "\n", 207);
		break;
	}
	default:
		break;
	}
	return 0;
}

bool FileExists(const std::string& path)
{
	std::ifstream f(path.c_str());
	return f.good();
}

auto main(int argc, char** argv) -> int
{
	// Console
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle("Warp Logging Utility");

	 WFile::WriteAllText("tmpWlog.wlog", "");

	while (true)
	{
		// Format: (std::string)time::(int)LEVEL::(std::string)msg
		if (FileExists("init.wcm"))
		{
			std::vector<std::string>* currentCmd = new std::vector<std::string>();
			*currentCmd = WFile::ReadAllLines("tmpWlog.wlog");
			WFile::WriteAllText("tmpWlog.wlog", "");
			
			for (int i = 0; i < currentCmd->size(); i++)
			{
				Parse(currentCmd->at(i));
			}

			delete currentCmd;
			remove("init.wcm");
		}
	}

	return false;
}
