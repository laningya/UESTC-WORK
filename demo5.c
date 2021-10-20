#include <stdio.h>
#define MAX 10 
typedef struct 
{
	int serial_number;
	char name[10];
	char author[10];
	float price;
}bookinfo;
typedef struct
{
	bookinfo data[MAX];
	int num;
}listtype;
int main()
{
	listtype book1={{1,"Basic","zhang",15.00},{2,"VB","li",20.00},{3,"C","wang",18.00},{4,"delphi","zhao",23.00}};


}
