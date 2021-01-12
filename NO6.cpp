#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node *next;
};

static void manipulate(struct Node** headRef)
{
	struct Node *sebelum = NULL;
	struct Node *skrg = *headRef;
	struct Node *next = NULL;
	while (skrg != NULL) {
		next = skrg->next;
		skrg->next = sebelum;
		sebelum = skrg;
		skrg = next;
	}
	*headRef = sebelum;
}

void push(struct Node** headRef, int newData)
{
	struct Node *newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}


void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


int main()
{
	
	struct Node *head = NULL;

	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("Sorted Ascending\n");
	printList(head);
	manipulate(&head);
	printf("\nSorted Descending \n");
	printList(head);
	getchar();
}
