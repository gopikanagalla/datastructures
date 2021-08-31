#include<stdio.h>
#include<stdlib.h>
typedef struct book
{
	int id;
	struct book *next;
}book;
book *createnode()
{
	book *p=NULL;
	p=(book*)malloc(sizeof(book));
	scanf("%d",&p->id);
	p->next=NULL;
	return p;
}
void traverse(book *t)
{
	if(t==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("the data is:");
	while(t!=NULL)
	{
		printf("%d ",t->id);
		t=t->next;
	}

	printf("\n");
}
//insert at a position using call by value(return statement is used)
book *insert1(book *head,int k)
{
	int i;
	book *p=NULL,*new=NULL;
	printf("enter data to be inserted:");
	new=createnode();
	p=head;
	if(k==1)
	{
		new->next=head;
		head=new;
	}
	else
	{
		i=1;p=head;
		while(p!=NULL && i<k-1)
		{	
			p=p->next;
			i++;

		}
		if(p==NULL)
		{
			printf("insertion not possible\n");
		}
		else
		{
		new->next=p->next;
		p->next=new;
		}
	}
	return head;
}
//insert before a given key using call by reference
void insert2(book **head,int key)
{
	book *p=NULL,*new=NULL;
	printf("enter data to be inserted:");
        new=createnode();
	p=*head;
	if(p->id==key)
        {
                new->next=*head;
                *head=new;
        }
	else
	{
		while(p->next && p->next->id!=key)
		{
			p=p->next;
		}
		if(!p->next)
			printf("key not found\n");
		else
		{
			new->next=p->next;
			p->next=new;
		}
	}	
}
//insert after a given key
void insert3(book *head,int key)
{
	book *p=NULL,*new=NULL;
        printf("enter data to be inserted:");
        new=createnode();
	p=head;
	while(p && p->id!=key)
        {
 		p=p->next;
        }
	if(!p)
		printf("key not found\n");
	else
	{
		new->next=p->next;
        	p->next=new;
	}
}
//delete a node with given key using call by value
book *delete(book *head,int key)
{
	book *p=NULL,*q=NULL,*new=NULL;
	p=head;
	if(p->id==key)
	{
		head=p->next;
		free(p);
	}
	else
	{
		while(p->next && p->next->id!=key)
                {
                        p=p->next;
                }
		if(!p->next)
			printf("key not found\n");
		else
		{
		q=p->next;
		p->next=q->next;
		free(q);
		}
			
	}
	return head;
}
void reverse(book **head)
{
	book *P=NULL,*Q=NULL,*R=NULL;//Previous,current,next
	Q=*head;
	while(Q!=0)
	{
		R=Q->next;
		Q->next=P;
		P=Q;
		Q=R;
	}
	*head=P;
}
int main()
{
	book *head=NULL,*new=NULL,*last=NULL;
	int n,i,ch,key;
	char c;
	printf("enter no of nodes:");
	scanf("%d",&n);
	printf("enter %d values:",n);
	for(i=1;i<=n;i++)
	{
		new=createnode();
		if(new==NULL)
			printf("list is empty\n");
		if(head==NULL)
			head=new;
		else
			last->next=new;
		last=new;
	}
	do
	{
	printf("enter your choice\n");
	printf("1.traverse\n2.insert at a position\n3.insert before a given key\n4.insert after a given key\n5.delete a node with given key\n6.reverse\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:traverse(head);break;
		case 2:
	                printf("enter a kth position to insert new node:");
		        scanf("%d",&key);
		       	head=insert1(head,key);
			break;
		case 3:
			printf("enter a key value to insert new node at before key:");
		        scanf("%d",&key);
			insert2(&head,key);break;
		case 4:
			printf("enter a key value to insert new node at after key:");
		        scanf("%d",&key);
			insert3(head,key);break;
		case 5:
			 printf("enter a key value to delete a node at given key:");
		 	 scanf("%d",&key);
		 	 head=delete(head,key);break;
		case 6:
			 reverse(&head);break;
		default:printf("invalid choice\n");
	}
	printf("do u want to continue y/n:");
	getchar();
	scanf("%c",&c);
	}while(c=='y');
	return 0;
}
