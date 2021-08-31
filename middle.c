// Find middle node of a linked list
#include <stdio.h>
#include<stdlib.h>
typedef struct number
{
  int num;
  struct number *next;
}number;
number *createnode();
void traverse(number *t);
void middle_node(number *head);
int main()
{
  int n,i;
  number *head=NULL,*new=NULL,*last=NULL;

  printf("enter number of nodes(odd value):");
  scanf("%d",&n);
  if(n%2==0)
  {
    printf("Entered value is not odd\n");
    return 0;
  }
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
middle_node(head);
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

void middle_node(number *head)
{
  number *p=head,*q=head;
  while(q->next)
  {
    p=p->next;
    q=q->next->next;
  }
  printf("middle node is:%d\n",p->num);
}
