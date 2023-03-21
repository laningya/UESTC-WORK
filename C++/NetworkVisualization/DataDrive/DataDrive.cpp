#include "DataDrive.h"


DataDrive::DataDrive()
{

}

int DataDrive::fileType(string filePath)
//�ж��ļ����ͣ����Ϊ.txt������1�����Ϊ.csv������Ϊ2����������Ƿ���0
{
	if (filePath.rfind(".txt") != string::npos)
		return 1;
	else if (filePath.rfind(".csv") != string::npos)
		return 2;
	else
		return 0;
}

vector<int> DataDrive::stringToInt(string s)
//���ַ����е���ת��Ϊ����vector
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
//�ļ��е����ݻ�ȡΪvector<vector<int>>
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
		istringstream readstr(buf);  //string��������
		for (int i = 0; i < 100; i++)   //�ɸ������ݵ�ʵ�����ȡѭ����ȡ
		{
			getline(readstr, number, ',');  //ѭ����ȡ����
			arrInt.push_back(atoi(number.c_str())); //�ַ���תint
		}
		arrArrInt.push_back(arrInt);
	}
	ifs.close();
	return arrArrInt;
}