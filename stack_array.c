#include<stdio.h>
int ar[100];
int head=-1;
void push()
{
 if(head==99)
 printf("\nThe stack is full ");
 else
 {
 head++;
 printf("\nEnter value to be inserted: ");
 scanf("%d",&ar[head]);
 }
}
void pop()
{
 if(head==-1)
 printf("\nThe stack is empty");
 else
 {
 printf("Deleted element is: %d",ar[head]);
 head--;
 }
}
void display()
{
 int i;
 printf("Stack elements in order of accessing: ");
 for(i=head;i>=0;i--)
 printf("\n%d",ar[i]);
}
void displayrev()
{
 int i;
 printf("Stack elements in inserted order : ");
 for(i=0;i<=head;i++)
 printf("\n%d",ar[i]);
}
void peek()
{
 printf("Element in head/peek is %d",ar[head]);
}
void main()
{
 int ch;
 do
 {
 printf("\nMenu\n1.Push\n2.Pop\n3.Peek\n4.Display in accessing order\n5.Display in inserted order\n6.Exit\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 push();
 break;
 case 2:
 pop();
 break;
 case 3:
 peek();
 break;
 case 4:
 display();
 break;
 case 5:
 displayrev();
 break;
 case 6:
 break;
 default:
 printf("Wrong input. Try again");
 }
 }while(ch!=6);
}