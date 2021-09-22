# include <stdio.h>
int arr[100],n=0;

void display()
{       int i;
	if(n==0)
	{
		printf("Heap is empty\n");
		return;
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void insert(int num,int loc)
{
	int parent;
	while(loc>0)
	{
		parent=(loc-1)/2;
		if(num>=arr[parent])
		{
			arr[loc]=num;
			return;
		}
		arr[loc]=arr[parent];
		loc=parent;
	}
	arr[0]=num;
}
void del(int num)
{
	int left,right,i,temp,parent;

	for(i=0;i<n;i++)
	{
		if(num==arr[i])
		break;
	}
	if( num!=arr[i] )
	{
		printf("%d not found in heap\n",num);
		return;
	}
	arr[i]=arr[n-1];
	n=n-1;
	parent=(i-1)/2;
	if(arr[i] < arr[parent])
	{
		insert( arr[i],i);
		return;
	}
	left=2*i+1;
	right=2*i+2;
	while(right < n)
	{
		if( arr[i]<=arr[left] && arr[i]<=arr[right] )
			return;
		if( arr[right]>=arr[left] )
		{
			temp=arr[i];
			arr[i]=arr[left];
			arr[left]=temp;
			i=left;
		}
		else
		{
			temp=arr[i];
			arr[i]=arr[right];
			arr[right]=temp;
			i=right;
		}
		left=2*i+1;
		right=2*i+2;
	}
	if( left==n-1 && arr[i]>arr[left] )
	{	temp=arr[i];
		arr[i]=arr[left];
		arr[left]=temp;
	}
}

void main()
{
	int choice,num;
	do
	{
		printf("1.Insert");
		printf("\t\t\t2.Delete\n");
		printf("3.Display\t\t\t");
		printf("4.Quit\n");
		printf("Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			printf("Enter value : ");
			scanf("%d",&num);
			insert(num,n);
			n=n+1;
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			display();
			break;
		 case 4:
            break;
		 default:
			printf("Wrong choice\n");
		}
	}while(choice!=4);
}