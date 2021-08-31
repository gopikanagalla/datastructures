#include <stdio.h>
#include<stdlib.h>
typedef struct number
{
	int num;
	struct number *next;
}number;
number *createnode()
{
        number *ptr=NULL;
        ptr=(number*)malloc(sizeof(number));
        if(ptr==NULL)
                return ptr;
        printf("enter an element:");
        scanf("%d",&ptr->num);
        ptr->next=NULL;
        return ptr;
}
void push(number **top)
{
  number* new=NULL;
  new = createnode();
  if(new==NULL)
  {
    printf("heap is full\n\n");
    return;
  }
  new->next=(*top);//Head insertion
  (*top)=new;
}
int pop(number **top)
{
  int x;
  number *temp=NULL;
  if(*top==NULL)
  {
    return -1;
  }
  x=(*top)->num;
  temp=*top;
  *top =(*top)->next;
  free(temp);
 return x;
}
void traverse(number *t)
{
  if(t==NULL)
  {
    printf("stack is empty\n");
    return;
  }
	printf("the stack data is:");
	while(t!=NULL)
	{
		printf("%d ",t->num);
		t=t->next;
	}
	printf("\n");
}
int main()
{
  int op,del;
  number *top=NULL;
	do
	{
		printf("enter your choice\n");
		printf("1.push\n2.pop\n3.print_stack\n4.quit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:push(&top);break;
			case 2: del=pop(&top);
				if(del==-1)
					printf("stack is empty\n");
				else
					printf("%d is deleted\n",del);
				break;
    		  	case 3:traverse(top);break;
      			case 4: return 0;
			default:printf("invalid choice\n");
		}
	}while(1);
  return 0;
}
