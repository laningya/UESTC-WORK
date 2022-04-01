#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct list
{
	int data[MAX];
	int length;
}TYPELIST;
int main()
{
	int i;
	TYPELIST *p=(TYPELIST *)malloc(sizeof(TYPELIST));
	p->data[0]=1;
	p->data[1]=2;
	p->data[2]=3;
	p->data[3]=4;
	p->data[4]=6;
	p->length=5;
	p->data[3]=p->data[4];
	p->length-=1;
	for(i=0;i<p->length;i++)
		printf("%d\n",p->data[i]);
	return 1;
}
