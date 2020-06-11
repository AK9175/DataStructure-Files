#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *r;

class Tree{
	public :
		char n;
		void createRoot(struct Node *root){
			struct Node *temp;
			f:
			temp = (struct Node *)malloc(sizeof(struct Node));
			r = root;
			cout<<"Enter the element";
			cin>>temp->data;
			temp->left = NULL;
			temp->right = NULL;
			d:
			cout<<"Where do you want to traverse for next L for Left or R for Right or S for Stop(from the root node)";
			cin>>n;
			if(n == 'l' || n == 'L'){
				if(root->left != NULL){
					cout<<root->data<<"->";
					root = root->left;
					goto d;
				}
				else if(root->left == NULL){
					cout<<root->data<<"->";
					root->left = temp;
					cout<<"Element inserted";
					root = r;
					goto f;
				}
			}
			else if(n == 'r' || n == 'R'){
				if(root->right != NULL){
					cout<<root->data<<"->";
					root = root->right;
					goto d;
				}
				else if(root->right == NULL){
					cout<<root->data<<"->";
					root->right = temp;
					cout<<"Element inserted";
					root = r;
					goto f;
				}
			}
			else if(n == 's' || n == 'S'){
				return ;
			}
		}
		
		void preorder(struct Node *root){
			if(root == NULL){
				return;
			}
			cout<<root->data<<" ";
			preorder(root->left);
			preorder(root->right);
		}
};

int main(){
	Tree T;
	struct Node *root;
	cout<<"Enter the root node";
	root = (struct Node *)malloc(sizeof(struct Node));
	cin>>root->data;
	root->left = root->right = NULL;
	T.createRoot(root);
	cout<<"\n";
	T.preorder(root);
	}
