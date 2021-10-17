#include <stdio.h>
#include <stdlib.h>
typedef struct list//定义单链表节点
{
	char data;
	struct list *next;
}node;
int creat(node *h)//单链表创建
{
	node *q;
	char c;
	q=h;
	c=getc(stdin);
	while(c!='\n')
	{
		node *p=(node *)malloc(sizeof(node));
		q->next=p;
		p->data=c;
		q=p;
		c=getc(stdin);
	}
	q->next=NULL;
	return 1;
}
int traverse(node *h)//单链表遍历
{
	node *q;
	q=h->next;
	while(q!=NULL)
	{
		printf("%c\n",q->data);
		q=q->next;
	}
	return 1;
}
int length(node *h)//求单链表长度
{
	node *q;
	q=h->next;
	int sum=0;
	while(q!=NULL)
	{
		sum++;
		q=q->next;
	}
	return sum;
}
int printnum(node *h,int location)//输出指定位置对应的元素
{
	if(location<=0)
	{
		printf("input is error");
		return 0;
	}
	node *q;
	q=h->next;
	while(location!=0&&q!=NULL)
	{
		q=q->next;
		location--;
	}
	return 1;
}
int search(node *h,char input)//查找某个元素的位置
{
	node *q;
	int i,j;
	q=h->next;
	for( i=1;q!=NULL;i++)
	{
		if(q->data==input)
		{
			j=1;
			break;
		}
		q=q->next;
	}
	if(j==1)
		printf("your search data order is %d\n",i);
	else
		printf("you search data is not in this linklist");
	return i;
}
int insert(node *h,int location,char input)//指定位置插入指定元素
{
	int lengths=length(h);
	if(location<1||lengths<location)
	{
		printf("input is error\n");
		return 0;
	}
	node *q,*s;
	q=h;
	while(location!=1)
	{
		q=q->next;
		location--;
	}
	node *t=(node *)malloc(sizeof(node));
	t->data=input;
	s=q->next;
	q->next=t;
	t->next=s;
	return 1;
}
int del(node *h,int location)//删除指定位置的元素
{
	int lengths=length(h);
	if(location<1||lengths<location)
	{
		printf("your input is error");
		return 0;
	}
	node *q,*s;
	q=h;
	while(location!=1)
	{
		q=q->next;
		location--;
	}
	s=q->next;
	q->next=q->next->next;
	free(s);
	return 1;
}
int freelist(node *h)//释放单链表
{
	node *q,*s;
	q=h->next;
	while(q!=NULL)
	{
		s=q->next;
		free(q);
		q=s;
	}
	return 1;
}
int main()
{
	node *head=(node *)malloc(sizeof(node));//申请头节点并初始化单链表
	head->next=NULL;
	creat(head);
	if(head->next==NULL)
	{
		printf("this linklist is null\n");
		return 0;
	}
	traverse(head);
	int l=length(head);
	printf("this linklist length is %d\n",l);
	printnum(head,3);
	search(head,'a');
	insert(head,4,'f');
	traverse(head);
	del(head,3);
	traverse(head);
	freelist(head);
	return 1;
}
