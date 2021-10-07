//考虑到为确定个数的处理对象：即10个整数，且不涉及插入、排序等操作，所以采用顺序表的数据结构
#include <stdio.h>
int main()
{
	int a[10],*p,*q,*s,swap;
	for(int i=0;i<10;i++ )//输入10个整数
	{
		scanf("%d",&a[i]);
	}
	s=a;
	p=a;
	q=a;
	for(int i=1;i<10;i++)//寻找最大值和最小值的指针
	{
		if(*(s+i)<*p)
		{
			p=(s+i);
		}
		if(*(s+i)>*q)
		{
			q=(s+i);
		}
	}
	swap=*s;//按照题目要求交换值
	*s=*p;
	*p=swap;
	swap=*(s+9);
	*(s+9)=*q;
	*q=swap;
	for(int i=0;i<10;i++)//打印输出这10个整数
	{
		printf("%d\n",*(s+i));
	}
	return 0;
}
