#include<stdio.h>
#include<stdlib.h>
typedef struct number
{
	int num;
	struct number *next;
}Queue;
void Enque(Queue **Head,Queue **Tail)
{
	Queue*new=NULL;
	new=(Queue*)malloc(sizeof(Queue));
	if(new==NULL)
	{
		printf("Heap is out of space\n");
		return;
	}
	new->next=0;
  printf("enter an element:");
	scanf("%d",&new->num);
	if(*Tail==NULL)
	{
		*Tail=new;
		*Head=new;
		return;
	}
	(*Tail)->next=new;
	*Tail=new;
}

int Deque(Queue **Head,Queue **Tail)
{
	int x;
	Queue *temp;
	if(*Head==NULL)
	{
		return -1;
	}
	x=(*Head)->num;
	temp=*Head;
	*Head=(*Head)->next;
	free(temp);
	if(*Head==NULL)
		*Tail=NULL;
	return x;
}

void Print_Queue(Queue *Head)
{
  printf("elements in queue:");
	while(Head)
	{
		printf("%d ",Head->num);
		Head=Head->next;
	}
	printf("\n");
}

int main()
{
	Queue *Head=NULL,*Tail=NULL;
	int ch,del;
	do
	{
  	printf("Enter an option:\n");
	printf("1.ENQUE\n2.DEQUE\n3.PRINT\n4.QUIT\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:Enque(&Head,&Tail);
		       break;
		case 2:del=Deque(&Head,&Tail);
		       if(del==-1)
			       printf("Queue is empty\n");
		       else
			       printf("%d is deleted\n",del);
		       break;
		case 3:Print_Queue(Head);break;
    		case 4:return 0;
    		default: printf("invalid choice\n");
	}
	}while(1);
	return 0;
}
