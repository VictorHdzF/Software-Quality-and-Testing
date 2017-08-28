#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "MemoryCheck.h"

using namespace std;

class Scanner
{
public:
	vector<int> openPorts;
	ifstream inFile;
	string x, line;

	vector<int> openPortsList()
	{
		system("nmap -sTU localhost | grep -i open > ports.txt");

		inFile.open("ports.txt");
		if (!inFile) {
			cout << "Unable to open file" << endl;
			exit(1);
		}

		while (getline(inFile, x))
		{
			line = x.substr(0, x.find("/", 0));
			openPorts.push_back(stoi(line));
		}

		inFile.close();

		return openPorts;
	}

	bool openPort(int p)
	{
		for (int i = 0; i < openPorts.size(); i++)
		{
			if (p == openPorts[i])
				return true;
		}
		return false;
	}
};