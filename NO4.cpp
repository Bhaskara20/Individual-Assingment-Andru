#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};


void unduplicate(struct Node *head)
{
	
	struct Node *skrg = head;
    struct Node *next2; 

	if (skrg == NULL) 
	return; 

	while (skrg->next != NULL) 
	{
	
	if (skrg->data == skrg->next->data) 
	{		
		next2 = skrg->next->next;
		free(skrg->next);
		skrg->next = next2; 
	}
	else
	{
		skrg = skrg->next; 
	}
	}
}


void push(struct Node** headref, int newdata)
{
	
	struct Node *newnode =
			(struct Node*) malloc(sizeof(struct Node));
			

	newnode->data = newdata;
	newnode->next = (*headref);	 
	(*headref) = newnode;
}


void printList(struct Node *node)
{
	while (node!=NULL)
	{
	printf("%d-> ", node->data);
	node = node->next;
	}
    puts("NULL");
} 

int main()
{
	
	struct Node *head = NULL;

	push(&head, 1);
	push(&head, 1);
	push(&head, 1); 
	push(&head, 2);
	push(&head, 3);
	push(&head, 3);
    push(&head, 4);
    push(&head, 4);
    push(&head, 5);								 

	printf("\n Linked list awal yang penuh duplikat dan dosa\n ");
	printList(head); 
    unduplicate(head); 
    printf("\n Linked list yang udah gaada duplikat dan suci dari dosa\n ");		 
	printList(head);		 

	return 0;
}
