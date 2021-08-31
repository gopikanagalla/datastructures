//Find nth node from the last
#include<stdio.h>
#include<stdlib.h>
typedef struct number
{
  int num;
  struct number *next;
}number;
number *createnode();
void traverse(number *t);
void nth_node_from_last(number *head,int l);
int main()
{
  int n,i;
  number *head=NULL,*new=NULL,*last=NULL;

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
  traverse(head);
  nth_node_from_last(head,n);
  return 0;
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

void nth_node_from_last(number *head,int l)
{
  number *p=head,*q=head;
  int n;
   printf("enter nth node from last:");
  scanf("%d",&n);

  if(n<=l)
  {
     printf("node%d element from last is ",n);
    while(n)
    {
      q=q->next;
      n--;
    }
    while(q)
    {
      p=p->next;
      q=q->next;
    }
    printf("%d\n",p->num);
  }
  else 
  {
    printf("entered node doesnot exist\n");
  }
}
