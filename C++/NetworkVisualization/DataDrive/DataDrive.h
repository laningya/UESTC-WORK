#pragma once

#include "datadrive_global.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;


class DATADRIVE_EXPORT DataDrive
{
public:
    DataDrive();
	static int fileType(string);
	static vector<int> stringToInt(string);
	static vector<vector<int>> fileRead(string);
	static vector<vector<int>> csvRead(string);
	static vector<vector<int>> sqlRead(string);
};
