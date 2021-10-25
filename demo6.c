#include <stdio.h>
#include <stdlib.h>
typedef struct  list//定义单链表节点
{
	int data;
	struct list *next;
}node;
int creat(node *h)//单链表创建 说明：输入非整数作为输入结尾
{
	int c;
	node *q=h;
	while(scanf("%d",&c)==1)
	{
		node *p=(node *)malloc(sizeof(node));
		q->next=p;
		p->data=c;
		q=p;
	}
	q->next=NULL;
	return 1;
}
int length(node *h)//计算单链表长度
{
	node *q=h->next;
	int lengths=0;
	while(q!=NULL)
	{
		lengths++;
		q=q->next;
	}
	return lengths;
}
int search(node *h,int num)//查找某个数据的位置
{
	node *q=h->next;
	int order=0;
	while(q!=NULL)
	{
		order+=1;
		if(q->data==num)
		{
			return order;	
		}
		q=q->next;
	}
	return -1;
}
int delre(node *h)//删除重复元素
{
	node *q=h->next;
	while(q!=NULL)
	{
		node *s=q;
		while(s->next!=NULL)
		{
			if(s->next->data==q->data)
			{
				node *t=s->next;
				s->next=s->next->next;
				free(t);
				continue;
			}
			s=s->next;
		}
		q=q->next;
	}
	return 1;

}
int traverse(node *h)//单链表遍历
{
	node *q=h->next;
	while(q!=NULL)
	{
		printf("%d\n",q->data);
		q=q->next;
	}
	return 1;
}
int main()
{
	int input,i;
	node *head=(node *)malloc(sizeof(node));
	creat(head);
	int lengths=length(head);
	printf("该链表长度为:%d\n",lengths);
	i=search(head,3);
	if(i==-1)
		printf("该元素不存在\n");
	else
		printf("该元素的位置为:%d\n",i);
	search(head,7);
	if(i==-1)
	{
		printf("该元素不存在\n");
	}
	else
		printf("该元素位置为:%d\n",i);
	delre(head);
	traverse(head);
}
