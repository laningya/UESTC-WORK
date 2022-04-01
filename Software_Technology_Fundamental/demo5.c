#include <stdio.h>
#include <string.h>
#define MAX 10 
typedef struct //定义图书的结构体信息
{
	int serial_number;
	char name[10];
	char author[10];
	float price;
}bookinfo;
typedef struct//定义顺序表
{
	bookinfo data[MAX];
	int num;
}listtype;
int main()
{
	listtype book1={(bookinfo){1,"Basic","zhang",15.00},(bookinfo){2,"VB","li",20.00},(bookinfo){3,"C","wang",18.00},(bookinfo){4,"delphi","zhao",23.00}};/*对于结构体的初始化前面要强制类型转换*/
	listtype *p=&book1;
	p->num=4;
	p->data[2].serial_number=p->data[3].serial_number;//将第四本图书信息赋值给第三本图书
	strcpy(p->data[2].name,p->data[3].name);
	strcpy(p->data[2].author,p->data[3].author);
	p->data[2].price=p->data[3].price;
	p->num-=1;
	for(int i=0;i<p->num;i++)
	{
		printf("%d\n",p->data[i].serial_number);
		printf("%s\n",p->data[i].name);
		printf("%s\n",p->data[i].author);
		printf("%f\n",p->data[i].price);
	}
	return 1;
}
