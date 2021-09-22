#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int num;
    struct tree *left;
    struct tree *right;
};
struct tree* newNode(int item)
{
	struct tree* temp
		= (struct tree*)malloc(sizeof(struct tree));
	temp->num = item;
	temp->left = temp->right = NULL;
	return temp;
}
void inorder(struct tree* t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf(" %d ",t->num);
        inorder(t->right);
    }
}
void preorder(struct tree* t)
{
    if(t!=NULL)
    {
        printf(" %d ",t->num);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(struct tree* t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf(" %d ",t->num);
    }
}
struct tree* insert(struct tree *node,int val)
{
    if(node==NULL)
    {
        return newNode(val);
    }
    if(node->num>val)
    {
        node->left=insert(node->left,val);
    }
    else
        node->right=insert(node->right,val);

    return node;
}
struct tree* minvaluetree(struct tree* node)
{
    struct tree *current=node;
    while(current&&current->left!=NULL)
        current=current->left;
    return current;
}
struct tree* deleteNode(struct tree* root,int val)
{
    if (root== NULL)
		return root;
	if (val < root->num)
		root->left = deleteNode(root->left, val);
	else if (val > root->num)
		root->right = deleteNode(root->right, val);
	else
    {

		if (root->left == NULL)
		{
			struct tree* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct tree* temp = root->left;
			free(root);
			return temp;
		}

		struct tree* temp = minvaluetree(root->right);
		root->num = temp->num;
		root->right = deleteNode(root->right, temp->num);
	}
	return root;
}
void main()
{
    struct tree* mango=NULL;
    int key=0;
    int val,choice;
    mango=newNode(key);
    do{
    printf("\n1. Insert\t\t\t2.Delete\n3.inorder\t\t\t4.preorder\n5.postorder\t\t\t6.exit\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        if(key==0)
        {
            printf("Enter value: ");
            scanf("%d",&val);
            mango=newNode(val);
            key=1;
        }
        else
        {
            printf("Enter value: ");
            scanf("%d",&val);
            mango=insert(mango,val);
        }
        break;
    case 2:
            printf("Enter value to be deleted : " );
            scanf("%d",&val);
            if((mango->num==val&&mango->left==NULL)&&mango->right==NULL)
                key=0;
            mango=deleteNode(mango,val);
            break;
    case 3:
          printf("\nInorder : ");
          inorder(mango);
          break;
    case 4:
        printf("\npre order: ");
        preorder(mango);
        break;
    case 5:
          printf("\npost order: ");
        postorder(mango);
    case 6:
        break;
    default:
        printf("Wrong input try again");
    }
    }while(choice!=6);
}
