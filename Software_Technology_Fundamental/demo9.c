#include <stdio.h>
int bubble_sort(int a[],int num)//冒泡排序
{
	int i,j,temp;
	for(i=1;i<num;i++)
	{
		 for(j=0;j<num-i;j++)
		 {
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		 }
	}
	return 1;
}
int main()
{
	int a[5]={1,7,3,15,12};
	bubble_sort(a,5);
	for(int i=0;i<5;i++)
		printf("%d\n",a[i]);
	return 1;
}
