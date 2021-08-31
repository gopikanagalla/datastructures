/*Find if there is loop in a linked list (For this create a faulty list) and
 Remove loop from a linked list and print the list.(For this create a faulty list)*/
#include<stdio.h>
#include<stdlib.h>
typedef struct number
{
  int num;
  struct number *next;
}number;
number *createnode();
void traverse(number *t);
void reverse(number **h);
void find_remove_loop(number *head);
int main()
{
  int n,i,flag=0;
  number *head=NULL,*new=NULL,*last=NULL,*loop_node=NULL;
  printf("enter number of nodes:");
  scanf("%d",&n);
  printf("enter %d elements:",n);
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
  reverse(&head);//loop is created 
  find_remove_loop(head);
  traverse(head);
}

number *createnode()
{
	number *ptr=NULL;
	ptr=(number*)malloc(sizeof(number));
	scanf("%d",&ptr->num);
	ptr->next=NULL;
	return ptr;
}

void traverse(number *t)
{
  if(t==NULL)
  {
    printf("No nodes in list\n");
    return;
  }
	printf("the data is:");
	while(t!=NULL)
	{
		printf("%d ",t->num);
		t=t->next;
	}
	printf("\n");
}
//reverse the linked list 
void reverse(number **head)
{
	number *P = NULL, *Q = NULL , *R = NULL ;
	if(head != NULL)
	  P = *head;
  else 
  {
    printf("No elements in linked list\n");
    return;
  }
	if(P->next)
    Q = P->next;
  else
  {
    printf("List consists of one element\n");
    //traverse(*head);
    return;
  }
	if(Q->next)
	R = Q->next;
  else
  {
    Q->next=P;
    P->next = NULL;
    P=Q;
    //traverse(P);
    return;
  }
	
	while(Q != NULL)
	{
		Q->next=P;
		P=Q;
		Q=R;

		if(R != NULL)
		R = R -> next;
	}
	//(*head)->next = NULL;
  //traverse(P);
  (*head)=P;
}
void find_remove_loop(number* head)
{
  number *p=head,*q=head,*r=NULL;
  while(q!=NULL)
  {
    p=p->next;
    q=q->next->next;
    if(p==q)
    {
      break;
      }
    }
   /* if(p==q)
    {
    q=head;
      while(p!=q)
      {
        r=p;
        p=p->next;
        q=q->next;
      }
    }
    r->next=NULL;*/
}


