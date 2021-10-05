#include <stdio.h>
#include <stdlib.h>
float *score(float *p,float *q);
int main()
{
	float *p=(float *)malloc(sizeof(float)*10);//malloc申请10个float空间存放考试成绩
	float *q=(float *)malloc(sizeof(float)*10);//malloc申请10个float空间存放平时成绩
	*p=88.5;//写入成绩
	*(p+1)=76;
	*(p+2)=83.5;
	*(p+3)=92;
	*(p+4)=96.5;
	*(p+5)=80;
	*(p+6)=62;
	*(p+7)=85.5;
	*(p+8)=74;
	*(p+9)=87.5;
	*q=4.0;
	*(q+1)=3.5;
	*(q+2)=4.5;
	*(q+3)=2.0;
	*(q+4)=3.0;
	*(q+5)=3.5;
	*(q+6)=4.0;
	*(q+7)=2.5;
	*(q+8)=3.5;
	*(q+9)=4.0;
	float *r=score(p,q);
	printf("%f\n",*r);
	for(int i=1;i<11;i++)
	{
		printf("%f\n",*(r+i));
	}
	return 1;
}
float *score(float *s,float *t)//实现求考试成绩平均分，每个学生总成绩，并将结果通过指针
{
	float *a=(float *)malloc(sizeof(float)*11);
	*a=0;
	for(int i=0;i<10;i++)
	{
		*a+=*(s+i);
		*(a+i+1)=*(s+i)+*(t+i);
	}
	*a=*a/10;
	return a;
}
