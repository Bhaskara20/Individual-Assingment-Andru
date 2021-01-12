#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

void printMid(struct Node *head) 
{ 
	struct Node *slowptr = head; 
	struct Node *fastptr = head; 

	if (head!=NULL) 
	{ 
		while (fastptr != NULL && fastptr->next != NULL) 
		{ 
			fastptr = fastptr->next->next; 
			slowptr = slowptr->next; 
		} 
		printf("Elemen yang ada di tengah yaitu data [%d]\n\n", slowptr->data); 
	} 
} 

void push(struct Node** headref, int newdata) 
{ 
	
	struct Node *new_node = 
		(struct Node*) malloc(sizeof(struct Node)); 

	
	new_node->data = newdata; 
	new_node->next = (*headref); 
	(*headref) = new_node; 
} 
 
void printList(struct Node *ptr) 
{ 
	while (ptr != NULL) 
	{ 
		printf("%d->", ptr->data); 
		ptr = ptr->next; 
	} 
	printf("NULL\n"); 
} 

int main() 
{ 
	
	struct Node *head = NULL; 
	int i; 

	 
		push(&head, 1);
        push(&head, 2);
        push(&head, 3);
        push(&head, 4);
        push(&head, 5);

		printList(head); 
		printMid(head); 
	 

	return 0; 
} 
