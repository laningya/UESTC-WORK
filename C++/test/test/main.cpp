#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //��׼�㷨��
using namespace std;

void myPrint(int val)
{
	cout << val << endl;
}
void test0()
{
	vector<int> a;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i + 1);
	}
	a.push_back(11);
	//��һ�ֱ���
	vector<int>::iterator itBegin = a.begin();  //ָ�������е�һ��Ԫ��
	vector<int>::iterator itEnd = a.end();     //ָ�����������һ��Ԫ����һ����ַ
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	//�ڶ��ֱ���
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
		cout << *it << endl;
	//�����ֱ���
	for_each(a.begin(), a.end(), myPrint);
	
	cout << "\n" << endl;

	//�����С
	cout << a.size() << endl;
}
//�ַ�����ֵ
void test1()
{
	string s1 = "hello world";
	string s2;
	s2.assign(s1);
	cout << s2 << endl;
	
}
//�ַ���ƴ��
void test2()
{
	string s1 = "hello world\n";
	string s2 = "hello c++\n";
	//s1 += "hello c++\n";
	//s1.append("hello python");
	s1.append(s2, 0, 2);
	cout << s1 << endl;
}
//�ַ�������
void test3()
{
	string s1 = "hello world";
	cout << s1.find("elll") << endl;
	//string.rfind���شӺ�����ҵĽ��
}
//�ַ����滻
void test4()
{
	string s1 = "hello world";
	s1.replace(0,2,"hee");  //��0��ʼ����������ַ��滻Ϊ"hee"
	cout << s1 << endl;
}
//�ַ����Ƚ�
void test5()
{
	string s1;
	s1 = "hello world";
	string s2 = string("hello c++");
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s2.compare(s1) << endl;
	cout << s1.compare(s2) << endl;
}
//�ַ�����ȡ
void test6()
{
	string s1;
	cout << "������s1 " << endl;
	cin >> s1;
	//����ʹ��s1[i]���޸��ַ���s1
}
//�ַ����Ĳ���
void test7()
{
	string s1 = "hello world";
	s1.insert(0, "c++");
	cout << s1 << endl;
}
void test8()
{
	string s1 = "hello world";
	s1.erase(0, 2);//ɾ����0��ʼ��2���ַ�
	cout << s1 << endl;
}
//�ַ��Ӵ���ȡ
void test9()
{
	string s1 = "hello world";
	string s2;
	s2 = s1.substr(0, 2);//��ȡ��0��ʼ��2���ַ�
	cout << s2 << endl;
}





void main()
{
	test0();
}
