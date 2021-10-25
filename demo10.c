#include <stdio.h>
int chose_sort(int a[],int num)//选择排序
{
	int i,j,min,temp;
	for(i=0;i<num-1;i++)
	{
		min=i;
		for(j=i+1;j<num;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
}
int main()
{
	int a[5]={1,7,3,18,14};
	chose_sort(a,5);
	for(int i=0;i<5;i++)
		printf("%d\n",a[i]);
	return 1;
}
