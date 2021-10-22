#include <stdio.h>
#include <stdlib.h>
typedef struct  list
{
	int data;
	struct list *next;
}node;
int creat(node *h)
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
int length(node *h)
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
int search(node *h,int num)
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
int delre(node *h)
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
int traverse(node *h)
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
	delre(head);
	traverse(head);
}
