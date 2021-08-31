/*17) Double linked list creation and printing forward and reverse direction
18) Insert a new node at a given position
19) Delete a node with a given key*/
#include<stdio.h>
#include<stdlib.h>
typedef struct number
{
	int num;
	struct number *next;
  	struct number *prev;
}number;
number *createnode();
void traverse_head(number *t);
void traverse_tail(number *t);
number *insert_at_position(number *head,int k);
number *delete(number *head,int key);

int main()
{
  int n,i,op,k;
  number *head=NULL,*new=NULL,*tail=NULL,*last=NULL;
  printf("enter number of nodes:");
  scanf("%d",&n);
  printf("enter %d elements:",n);
  for(i=1;i<=n;i++)
  {
	new=createnode();
	if(head==NULL)
    	{
		head=new;
        	tail=new;
    	}
	else
    	{
      		tail=new;
      		last->next = new;
		tail->prev=last;
    	}
		last=new;
	}
  while(1)
  {
  printf("Enter an option:\n");
  printf("1.traversal from first\n2.Traversal from last\n3.Insert at a position\n4.Delete certain key\n5.Quit\n");
  scanf("%d",&op);
  switch(op)
  {
    case 1: traverse_head(head);break;
    case 2: traverse_tail(tail);break;
    case 3: 
            printf("Enter a position to insert:");
            scanf("%d",&k);
            head = insert_at_position(head,k);
            break;
    case 4: printf("enter a key to delete:");
            scanf("%d",&k);
            head = delete(head,k);
            break;
    case 5: return 0;
    default: printf("invalid option\n\n");
  }
  }
  return 0;
}
number *createnode()
{
	number *ptr=NULL;
	ptr=(number*)malloc(sizeof(number));
	scanf("%d",&ptr->num);
	ptr->next=NULL;
  	ptr->prev = NULL;
	return ptr;
}
void traverse_head(number *t)
{
  if(t==NULL)
  {
    printf("No nodes in list\n\n");
    return;
  }
  printf("The data is:");
	while(t!=NULL)
	{
		printf("%d ",t->num);
		t=t->next;
	}
	printf("\n");
}
void traverse_tail(number *t)//reversing a dll
{
  if(t==NULL)
  {
    printf("No nodes in list\n\n");
    return;
  }
  printf("the data is:");
	while(t!=NULL)
	{
		printf("%d ",t->num);
		t=t->prev;
	}
	printf("\n");
}

number *insert_at_position(number *head,int k)
{
	int i;
	number *p=NULL,*new=NULL;
	printf("enter data to be inserted:");
	new=createnode();
	p=head;
	if(k==1)
	{
		new->next=head;
    		head->prev = new;
    		new->prev = NULL;
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
			printf("insertion not possible\n\n");
		}
		else
		{
     		  new->prev = p;
		  new->next=p->next;
		  p->next=new;
		}
	}
	return head;
}

number *delete(number *head,int key)
{
	number *p=NULL,*q=NULL,*new=NULL;
	p=head;
  if(head == NULL)
  {
    printf("list is empty\n\n");
    return head;
  }
  if(p->num==key && p->next == NULL)
	{
		head=p->next;
		free(p);
    		return head;
	}
	if(p->num==key )
	{
		head=p->next;
  		p->next->prev = NULL;
		free(p);
	}
	else
	{
		while(p->next && p->next->num!=key  )
                {
                        p=p->next;
                }
		if(!p->next)
			printf("key not found\n\n");
		else
		{
		  q=p->next;
    			  if(q->next !=NULL)
     			  {
		    		p->next=q->next;
       				q->next ->prev = p;
		    		free(q);
		          }
      			  else 
      			  {
       				 q=p->next;
        			 p->next = NULL;
        			 free(q);
      			  }
                 }
			
	}
return head;
}
