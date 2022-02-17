#include<stdio.h>
#include<stdlib.h>

struct node{
char data;
struct node *l;
struct node *r;
};

void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

void main()
{
	struct node *a, *b, *c, *d, *e, *f, *g, *t;
	a=(struct node *)malloc(sizeof(struct node));
	b=(struct node *)malloc(sizeof(struct node));
	c=(struct node *)malloc(sizeof(struct node));
	d=(struct node *)malloc(sizeof(struct node));
	e=(struct node *)malloc(sizeof(struct node));
	f=(struct node *)malloc(sizeof(struct node));
	g=(struct node *)malloc(sizeof(struct node));
	t=a;
	a->data='A';
	a->l=b;
	a->r=d;

	b->data='B';
	b->l=c;
	b->r=NULL;

	c->data='C';
	c->l=NULL;
	c->r=NULL;

	d->data='D';
	d->l=e;
	d->r=g;

	e->data='E';
	e->l=NULL;
	e->r=f;

	f->data='F';
	f->l=NULL;
	f->r=NULL;

	g->data='G';
	g->l=NULL;
	g->r=NULL;

printf("preorder is \n");
preorder(t);

printf("inorder is \n");
inorder(t);

printf("postorder is \n");
postorder(t);

printf("\nDone!");
}

void preorder(struct node *t)
{
if(t==NULL)
	printf("Empty");
else 
	{
	printf("%c ",t->data);
	if(t->l!=NULL)
		{
		preorder(t->l);
		}
	if(t->r!=NULL)
		{
		preorder(t->r);
		}
	}
}
void inorder(struct node *t)
{
if(t==NULL)
	printf("Empty");
else 
	{

	if(t->l!=NULL)
		{
		inorder(t->l);
		}
	printf("%c ",t->data);
	if(t->r!=NULL)
		{
		inorder(t->r);
		}
	}
}	
void postorder(struct node *t)
{
if(t==NULL)
	printf("Empty");
else 
	{

	if(t->l!=NULL)
		{
		postorder(t->l);
		}
	
	if(t->r!=NULL)
		{
		postorder(t->r);
		}
	}
	printf("%c ",t->data);
}	
