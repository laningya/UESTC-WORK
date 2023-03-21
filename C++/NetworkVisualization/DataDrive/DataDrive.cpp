#include "DataDrive.h"


DataDrive::DataDrive()
{

}

int DataDrive::fileType(string filePath)
//判断文件类型，如果为.txt，返回1；如果为.csv，返回为2；如果都不是返回0
{
	if (filePath.rfind(".txt") != string::npos)
		return 1;
	else if (filePath.rfind(".csv") != string::npos)
		return 2;
	else
		return 0;
}

vector<int> DataDrive::stringToInt(string s)
//将字符串中的数转换为整型vector
{
	vector<int> arrInt;
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			sum = sum * 10 + s[i] - 48;
		}
		else
		{
			arrInt.push_back(sum);
			sum = 0;
		}
	}
	arrInt.push_back(sum);
	return arrInt;
}

vector<vector<int>> DataDrive::fileRead(string filePath)
//文件中的数据获取为vector<vector<int>>
{
	ifstream ifs;
	string buf;
	vector<vector<int>> arrArrInt;

	ifs.open(filePath, ios::in);

	getline(ifs, buf);
	while (getline(ifs, buf))
	{
		arrArrInt.push_back(stringToInt(buf));
	}

	ifs.close();
	return arrArrInt;
}


vector<vector<int>> DataDrive::csvRead(string filePath)
{
	ifstream ifs;
	string buf;
	vector <vector<int>> arrArrInt;
	vector<int> arrInt;

	ifs.open(filePath, ios::in);

	getline(ifs, buf);
	while (getline(ifs, buf))
	{
		string number;
		istringstream readstr(buf);  //string数据流化
		for (int i = 0; i < 100; i++)   //可根据数据的实际情况取循环获取
		{
			getline(readstr, number, ',');  //循环读取数据
			arrInt.push_back(atoi(number.c_str())); //字符串转int
		}
		arrArrInt.push_back(arrInt);
	}
	ifs.close();
	return arrArrInt;
}