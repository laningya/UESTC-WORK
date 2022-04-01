#include <stdio.h>
int insert_order(int a[],int num)//插入排序
{
	int i,j,k,temp;
	for(i=1;i<num;i++)
	{
		if(a[i]<a[i-1])
		{
			temp=a[i];
			for(j=i-1;j>=0&&a[j]>temp;j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]=temp;
		}
	}
	return 1;
}
int main()
{
	int a[6]={1,7,3,5,18,12};
	insert_order(a,6);
	for(int i=0;i<6;i++)
		printf("%d\n",a[i]);
	return 1;
}
