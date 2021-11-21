#include<stdio.h>
#include<stdlib.h>
void add_binary();
void one_compliment();
void two_compliment();
void display();
struct node
{
	int data;
	struct node *nxt ;
    struct node *prev ;

};
struct node *head = NULL;
int main()
{
	int choice;
	
	while(1)
	{
		puts("\n");
		puts("1: COMPUTE 1's COMPLIMENT\n");
		puts("2: COMPUTE 2's COMPLIMENT\n");
		puts("3: ADD 2 BINARY NUMBER\n ");
		puts("4: DISPLAY\n");
		
		printf("ENTER CHOICE = ");
		scanf("%d",&choice);
		
		switch(choice)
		  {
			
			case 1:
				   one_compliment();
				   break;
				   
			case 2:
				   two_compliment();
				   break;
				   
			case 3:
				   add_binary();
				   break;
				   
			case 4:
				display();
				break;
				
			default:
					printf("INVALID CHOICE\n");
					break;
			
		  }
	}
	return 0;
}


void add_binary()
{
	int value;
	struct node *ptr=NULL;
	struct node*temp = head;
	
	ptr=(struct node*)malloc(sizeof(struct node));
	
	if(ptr==NULL)
	{
		printf("MEMORY ALLOCATION FAILED \n");
		return;
	}
	
	printf("ENTER VALUE = ");
	scanf("%d",&value);
	
	ptr->data = value;
    ptr->nxt = NULL;
    ptr->prev = NULL;
	
	if(head==NULL)
	{
		head = ptr;
		ptr->nxt = head;
	}	
	
	else
	{
		while(temp->nxt!=head)
		{
			temp = temp->nxt;
		}
		ptr->nxt = head;
		ptr->prev = temp;
		temp->nxt=ptr;
	}
	return;
}


void one_compliment()
{
	struct node*temp = head;
	
	if(head == NULL)
	{
		printf("LIST IS EMPTY \n");
		return;
	}
	
	else
	{
		while(temp->nxt!=head)
		{
			if(temp->data == 1)
			{
				temp->data = 0;
			}
			
			else if(temp->data == 0)
			{
				temp->data = 1;
			}
			
			else
			{
				printf("NUMBER NOT BINARY\n");
				return;
			}
			
			temp=temp->nxt;	
		}
		if(temp->data == 1)
			{
				temp->data = 0;
			}
			
		else if(temp->data == 0)
			{
				temp->data = 1;
			}
		
	}
	return;
}

void two_compliment()
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("LIST IS EMPTY \n");
		return;
	}
	else
	{
		while(temp->nxt!=head)
		{
			temp = temp->nxt;	
		}
		while(temp->data==0)
		{
			temp=temp->prev;
		}
					
	 }
	 printf("<<<here>>>==  %d",temp->data);	 
	 return;
	
}


void display()
{
	struct node*temp = head;
	
	
	if(head == NULL)
	{
		printf("LIST IS EMPTY \n");
		return;
	}
	
	else
	{
		
		while(temp->nxt!=head)
		{
			printf(" %d",temp->data);
			temp=temp->nxt;
		}
		printf(" %d",temp->data);
		
	}
	return;
}


