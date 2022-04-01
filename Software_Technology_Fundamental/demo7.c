#include <stdio.h>
int search(int a[],int num,int n)//二分查找
{
	int low,high,mid;
	low=0,high=num-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==n)
		{
			return mid;
		}
		else if(a[mid]>n)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return -1;
}
int main()
{
	int n,ret;
	int a[10]={1,3,15,22,27,50,60,88,92,105};
	printf("请输入要查找的元素\n");
	scanf("%d",&n);
	ret=search(a,10,n);
	if(ret==-1)
		printf("查找失败\n");
	else
	{
		printf("查找成功\n");
		printf("查找元素的序号为:%d",ret+1);
	}
	return 0;
}
