//考虑到要在主函数输入字符串，在func中统计大写、小写字母、数字、以及其他字符的个数，若使用逐次使用getc()函数没有体现出数据结构的作用（scnaf()函数与此思想基本一致）;若果使用gets()函数因为不能确定输入的的个数，gets()函数参数中数组指针对应的数组大小不容易确定，因而考虑使用单链表这一数据结构。
#include <stdio.h>
#include <stdlib.h>
typedef struct node1//定义单链表的节点
{
	char data;
	struct node1 *next;
}node;
int func(node *s,int a[])//传入单链表头节点指针以及记录数据的数组指针
{
	node *tmp1;
	tmp1=s->next;
	while(tmp1!=NULL)//对照ASCII码表得到下面的比较大小的语句
	{
		if((tmp1->data>=65)&&(tmp1->data<=90))
			a[0]+=1;
		else if((tmp1->data>=97)&&(tmp1->data<=122))
			a[1]+=1;
		else if((tmp1->data>=48)&&(tmp1->data<=57))
			a[2]+=1;
		else 
			a[3]+=1;
		tmp1=tmp1->next;
	}
	return 1;
}
int main()
{
	node *p,*q;
	char  c;
	int out[]={0,0,0,0};
	node *h=(node *)malloc(sizeof(node));//申请头节点
	h->next=NULL;
	q=h;
	c=getc(stdin);
	while(c!='\n')//单链表创建算法
	{
		node *p=(node *)malloc(sizeof(node));
		q->next=p;
		p->data=c;
		q=p;
		c=getc(stdin);	
	}
	q->next=NULL;
	for(p=h->next;p!=NULL;p=p->next)//链表遍历
	{
		printf("%c",p->data);
	}
	printf("\n");
	func(h,out);
	printf("大写字母个数为:%d\n",out[0]);
	printf("小写字母个数为:%d\n",out[1]);
	printf("数字个数为:%d\n",out[2]);
	printf("其他字符个数为:%d\n",out[3]);
	return 1;
}
