// Queueimplemented using linked list
#include<stdio.h>
#include<stdlib.h>
struct queue
{
 int data;
 struct queue *next;
};
struct queue *head=NULL;
struct queue *last=NULL;
void enqueue()
{
 struct queue *newnode=(struct queue*)malloc(sizeof(struct queue));
int val;
if((last!=NULL&&head!=NULL)&&newnode!=NULL)
{
 printf("Enter value: ");
 scanf("%d",&val);
 newnode->data=val;
 newnode->next=NULL;
 last->next=newnode;
 last=newnode;
}
else if(newnode==NULL)
 {
 printf("Memory not allocated");
 }
else
 {
 printf("Enter value: ");
 scanf("%d",&val);
 newnode->data=val;
 newnode->next=NULL;
 last=newnode;
 head=newnode;
 }
}
void dequeue()
{
 struct queue *newnode=(struct queue*)malloc(sizeof(struct queue));
 if(head!=NULL)
 {
 printf("Deleted value is %d ",head->data);
 newnode=head;
 head=newnode->next;
 free(newnode);
 }
 else
 {
 printf("Stack is empty");
 }
}
void display()
{
 struct queue *newnode=(struct queue*)malloc(sizeof(struct queue));
 newnode=head;
 printf("Elements in queue: ");
 while(newnode!=NULL)
 {
 printf(" %d ",newnode->data);
 newnode=newnode->next;
 }
}
void main()
{
 int ch;
 do
 {
 printf("\nMenu\n\n1.Enqueue\t\t\t2.dequeue\n3.Display\t\t\t4.Exit\nEnter your choice ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 enqueue();
 break;
 case 2:
 dequeue();
 break;
 case 3:
 display();
 break;
 case 4:
 break;
 default:
 printf("Invalid input. Try again");
}}while(ch!=4);
}