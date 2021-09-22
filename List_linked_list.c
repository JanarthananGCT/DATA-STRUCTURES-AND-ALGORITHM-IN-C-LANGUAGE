// program for linked list

#include <stdio.h>
#include <stdlib.h>

// creates a datatype node
typedef struct node{
	int num;
	struct node *next;
}node;


void printlist(node *list);
void searchdata(node *list, int data);
void searchindex(node *list, int pos);
void insertion(node *list, node *pos);
void deletion(node *list, node *pos);

void main1() {
	int n,i;

	printf("Size of linked list: ");
	scanf("%d", &n);

	node *list = malloc(sizeof(node));
	list->next = NULL;
	
	for(i = 0; i < n; i++) {
		int data;
		node *temp = list;
		node *newnode = malloc(sizeof(node));

		printf("enter data: ");
		scanf("%d", &data);
		newnode->num = data;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
	}

	printlist(list);
	
	int index, element, ch, index2 ;
	node *pos = NULL;
	printf(" Search by Index(1)\n Search by Element(2)\n Insertion (3)\n Deletion (4) \n Traversing(5): ");
	scanf("%d", &ch);
	

	node *temp = NULL;
	switch (ch) {
		case 1:
			printf("Search by index: ");
			scanf("%d", &index);

			searchdata(list, index);
			break;
		case 2:
			printf("Search by element: ");
			scanf("%d", &element);
		
			searchindex(list, element);
			break;
		case 3:
			printf("\nenter position where to insert(starting from 1): ");
			scanf("%d", &index2);

			temp = list;
			// to get previous node on that address
			for (i = 0; i < index2-1; i++) {
				temp = temp->next;
			}
			
			insertion(list, temp);
			printlist(list);

			break;
		case 4:
			printf("\nenter position where to delete(starting from 1): ");
			scanf("%d", &index2);

			// to get previous node on that address
			temp = list;
			for (i = 0; i < index2-1; i++) {
				temp = temp->next;
			}
			
			deletion(list, temp);
			printlist(list);

			break;
		case 5:
			printf("\nTraversing and printing elements:\n");
			printlist(list);

			break;
		default:
			printf("invalid choice\n");
	}

	
}

void printlist(node *list) {
	printf("\nprinting list: \n");

	node *temp = list->next;
	while(temp != NULL) {
		printf("%d -> ", temp->num);
		temp = temp->next;
	}
	printf("NULL\n\n");
}

void searchdata(node *list, int index) {
	// search by index (passes -1 if search by element)
	int i = 0;
	node *temp = list;
	for (i = 0; i < index; i++) {
		temp = temp->next;
	}

	printf("element at this index: %d\n", temp->num);
}
void searchindex(node *list, int data) {
	int i = 0;
	node *temp = list;
	while (temp != NULL) {
		i++;
		if (temp->num == data) {
			printf("Found at %d index\n", i-1);
			return;
		}
		temp = temp->next;
	}
	printf("Element not found\n");
}

void insertion(node *list, node *pos) {
	node *newnode = (node*) malloc(sizeof(node));

	int data;
	printf("enter data: ");
	scanf("%d", &data);

	newnode->num = data;

	node *temp = pos->next;
	pos->next = newnode;
	newnode->next = temp;
} 

void deletion(node *list, node *pos) {
	node *temp = pos->next;
	pos->next = temp->next;
	free(temp);
}
void main(){
	int a=1;
	while(a<=5)
	{
		main1();
		a++;
	}
}