#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //标准算法库
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
	//第一种遍历
	vector<int>::iterator itBegin = a.begin();  //指向容器中第一个元素
	vector<int>::iterator itEnd = a.end();     //指向容器中最后一个元素下一个地址
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	//第二种遍历
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
		cout << *it << endl;
	//第三种遍历
	for_each(a.begin(), a.end(), myPrint);
	
	cout << "\n" << endl;

	//计算大小
	cout << a.size() << endl;
}
//字符串赋值
void test1()
{
	string s1 = "hello world";
	string s2;
	s2.assign(s1);
	cout << s2 << endl;
	
}
//字符串拼接
void test2()
{
	string s1 = "hello world\n";
	string s2 = "hello c++\n";
	//s1 += "hello c++\n";
	//s1.append("hello python");
	s1.append(s2, 0, 2);
	cout << s1 << endl;
}
//字符串查找
void test3()
{
	string s1 = "hello world";
	cout << s1.find("elll") << endl;
	//string.rfind返回从后面查找的结果
}
//字符串替换
void test4()
{
	string s1 = "hello world";
	s1.replace(0,2,"hee");  //从0开始后面的两个字符替换为"hee"
	cout << s1 << endl;
}
//字符串比较
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
//字符串存取
void test6()
{
	string s1;
	cout << "请输入s1 " << endl;
	cin >> s1;
	//允许使用s1[i]来修改字符串s1
}
//字符串的插入
void test7()
{
	string s1 = "hello world";
	s1.insert(0, "c++");
	cout << s1 << endl;
}
void test8()
{
	string s1 = "hello world";
	s1.erase(0, 2);//删除从0开始的2个字符
	cout << s1 << endl;
}
//字符子串获取
void test9()
{
	string s1 = "hello world";
	string s2;
	s2 = s1.substr(0, 2);//获取从0开始的2个字符
	cout << s2 << endl;
}





void main()
{
	test0();
}
