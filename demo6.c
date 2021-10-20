#include <stdio.h>
#include <stdlib.h>
typedef struct  list
{
	int data;
	struct list *next;
}node;
int creat(node *h)
{
	/*char c;
	node *q=h;
	c=getc(stdin);
	while(c!='\n')
	{
		node *p=(node *)malloc(sizeof(node));
		q->next=p;
		p->data=(int)(c-48);
		q=p;
		c=getc(stdin);
	}*/
	/*int c;
	node *q=h;
	scanf("%d",&c);
	while(c!='\n')
	{
		node *p=(node *)malloc(sizeof(node));
		q->next=p;
		p->data=c;
		q=p;
		scanf("%d",&c);
	}*/
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
	int j=1,i;
	node *q=h->next;
	node *s=q->next;
	while(s!=NULL)
	{
		int k=0;
		node *t=h->next;
		for(i=j;i>0;i--)
		{
			if(s->data==t->data)
			{
				k=1;
				break;
			}
			t=t->next;
		}
		if(k==0)
		{
			s=s->next;
			q=q->next;
			j++;
		}
		else
		{
			q->next=s->next;
			node *r=s;
			s=s->next;
			free(r);
		}
	}
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
	traverse(head);
}
