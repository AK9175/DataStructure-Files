//Binary Search Tree.
#include<stdio.h>
#include <stdlib.h>
	struct Tree
	{
		int data;
	   struct	Tree *right;
	   struct	Tree *left;
	};
	struct Tree *temp;

	void preorder(struct Tree *r)
	{
		if(r == 0)
		{
			return ;
		}
		printf("%d ",r->data);
		preorder(r->left);
		preorder(r->right);
	}
	
		void inorder(struct Tree *r)
	{
		if(r == 0)
		{
			return ;
		}
		inorder(r->left);
		printf("%d ",r->data);
		inorder(r->right);
	}
	
			void postorder(struct Tree *r)
	{
		if(r == 0)
		{
			return ;
		}
		postorder(r->left);
		postorder(r->right);
		printf("%d ",r->data);
	}
	
	void Delete(int key , struct Tree *root , struct Tree *parent , struct Tree *r)
	{
		printf("root->value = %d",root->data);
		d:
		if(root->data > key)
		{
			parent = root;
			root = root->left;
			goto d;
		}
		else if(root->data < key)
		{
			parent = root;
			root = root->right;
			goto d;
		}
		else if(root->data == key)
		{
			if(parent->data > root->data)
			{
				parent->left = root->right;
				root->right->left = root->left;
			}
			else if(parent->data < root->data)
			{
				parent->right = root->right;
				root->right->left = root->left;
				free(root);
			}
		}
	}
int main()
{
//	struct Tree *A;
	int i = 1;
	int n,m;
	char y;
	struct Tree *root;
	struct Tree *parent;
	struct Tree *r;
	printf("Enter no of elements in BST");
	scanf("%d",&n);
	printf("Enter data in root node");
	temp = (struct Tree *)malloc(sizeof(struct Tree));
	scanf("%d",&temp->data);
	temp->right = 0;
	temp->left = 0;
	root = temp;
	r = root;
	d:  
     	if(i >= n)
	     {
	     		 printf("\n");
	     	printf("Binary search tree completed");
	     		 printf("\n");
	     	root = r;
			 preorder(root);
	    	 printf("\n");
	    	 inorder(root);
	    	 printf("\n");
	    	 postorder(root);
	    	 printf("\n");
	    	 b:
	     	printf("Enter the element you want to search");
	     	scanf("%d",&m);
	     	v:
	     		printf("%d",root->data);
	     //	printf("Comparision between");
	     //	printf("%d,%d",m,root->data);
	     	if(m >= root->data)
	     	{
	     	//	printf("%d",root->data);
	     			if(root->data == m)
	     			{
	     			//	printf("%d",root->data);
	     				printf("Element found");
	     				//return 0;
					 }
					 else
					 {
					 	root = root->right;
					//	printf("%d",root->data);
						printf(" --> ");
					 	goto v;
					    
					 }
				
			 }
			 else if(m <= root->data)
			 {
			 //	printf("%d",root->data);
			 //	printf("%d is less than %d",m,root->data);
			 		if(root->data == m)
			 		{
			 		//	printf("%d",root->data);
			 			printf("Element found");
			 			//return 0;
					 }
					 else
					 {
					 	root = root->left;
					// 	printf("%d",root->data);
					 	printf(" --> ");
					 	goto v;
			 }
	}
	root = r;
	printf("Enter the Elements you want to delete");
	scanf("%d",&m);
	Delete(m , root , parent , r);
	goto b;
}
	     else
	     {
	     	printf("Enter %d element ",i);
		temp = (struct Tree *)malloc(sizeof(struct Tree));
		scanf("%d",&temp->data);
		temp->left = 0;
		temp->right = 0;
		f:
		if(temp->data > root->data)
		{
			if(root->right == 0)
			{
				root->right = temp;
				root = r;
				i++;
				printf("Element added succesfully");
				printf("\n");
				goto d;
			}
			else if(root->right != 0)
			{
				root = root->right;
				goto f;
			}
		}
		else if(temp->data < root->data)
		{
			if(root->left == 0)
			{
				root->left = temp;
				root = r;
				i++;
				printf("Element added succesfully");
					printf("\n");
				goto d;
			}
			else if(root->left != 0)
			{
				root = root->left;
				goto f;
			}
		}
	}
}
