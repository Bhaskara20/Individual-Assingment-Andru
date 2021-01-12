#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node { 
	int data; 
	struct Node *next; 
}; 
 
int largestElement(struct Node *head) 
{ 
	 
	int max = INT_MIN; 
 
	while (head != NULL) { 		 
		if (max < head->data) 
			max = head->data; 
		head = head->next; 
	} 
	return max;
} 
 
int smallestElement(struct Node *head) 
{ 

	int min = INT_MAX; 
 
	while (head != NULL) { 
 
		if (min > head->data) 
			min = head->data; 

		head = head->next; 
	} 
	return min; 
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
	
	int maxval = largestElement(head);
	int minval = smallestElement(head);
	printf("\nRange nya adalah : %d",maxval - minval);
	

	return 0; 
} 
