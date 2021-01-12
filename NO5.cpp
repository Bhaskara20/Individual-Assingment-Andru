#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node 
{ 
int data; 
struct Node *next; 
}; 


void printNthFromLast(struct Node *head, int n) 
{ 
struct Node *mainptr = head; 
struct Node *refptr = head; 

int count = 0; 
if(head != NULL) 
{ 
	while( count < n ) 
	{ 
		if(refptr == NULL) 
		{ 
		printf("%d lebih besar dari nomor dari  "
					"nodes yang ada di daftar", n); 
		return; 
		} 
		refptr = refptr->next; 
		count++; 
	} 
	
	if(refptr == NULL) 
	{ 
		head = head->next; 
		if(head != NULL) 
			printf("Node ke- %d dari terakhir adalah %d ", n, mainptr->data); 
	} 
	else
	{ 
	while(refptr != NULL) 
	{ 
		mainptr = mainptr->next; 
		refptr = refptr->next; 
	} 
	printf("Node ke- %d dari terakhir adalah %d ", n, mainptr->data); 
	} 
} 
} 

// Function to push 
void push(struct Node** headref, int newdata) 
{ 
/* allocate node */
struct Node* newnode = new Node(); 

/* put in the data */
newnode->data = newdata; 

/* link the old list off the new node */
newnode->next = (*headref);	 

/* move the head to point to the new node */
(*headref) = newnode; 
} 

/* Driver program to test above function*/
int main() 
{ 
/* Start with the empty list */
struct Node* head = NULL; 
push(&head, 20); 
push(&head, 30); 
push(&head, 40); 
push(&head, 50);
push(&head, 60);
push(&head, 70);
push(&head, 80); 

printNthFromLast(head, 7); 
}
