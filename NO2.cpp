#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node { 
	int data; 
	struct Node *next; 
}; 
 
void largestElement(struct Node *head) 
{ 
	 
	int max = INT_MIN; 
 
	while (head != NULL) { 		 
		if (max < head->data) 
			max = head->data; 
		head = head->next; 
	} 
	printf("%d",max); 
} 
 
void smallestElement(struct Node *head) 
{ 

	int min = INT_MAX; 
 
	while (head != NULL) { 
 
		if (min > head->data) 
			min = head->data; 

		head = head->next; 
	} 
	printf("%d",min); 
} 

 
void push(struct Node** head, int data) 
{  
	struct Node *newNode = 
		(struct Node*)malloc(sizeof(struct Node)); 

 
	newNode->data = data;
	newNode->next = (*head);  
	(*head) = newNode; 
} 

// 
void printList(struct Node *head) 
{ 
	while (head != NULL) { 
		printf("%d -> ", head->data); 
		head = head->next; 
	} 
	puts("NULL"); 
} 

int main() 
{ 
	
	struct Node *head = NULL; 


	push(&head, 100); 
	push(&head, 99); 
	push(&head, 70); 
	push(&head, 80); 
	push(&head, 2); 
	
    printf("Linked list : \n");
    printList(head); 
	
    printf("\nElemen terbesar : \n"); 
    largestElement(head);
	
    printf("\n\nElemen terkecil : \n");  
	smallestElement(head); 

	return 0; 
} 
