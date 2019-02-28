#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
class tree
{
public:

	struct node* root;
	tree()
	{
		root = NULL;
	}
	struct node* insert(int ele, struct node* );
	void inorder(struct node*);
	int height(struct node *);
};
int tree::height(struct node *cur)
{
	if (cur == NULL)
		return 0;
	else
		return 1 + __max(height(cur->left), height(cur->right));
}
void tree::inorder(struct node *cur)
{
	if (cur != NULL) 
	{
		
		inorder(cur->left);
		cout << cur->data;
		inorder(cur->right);
	}
}
struct node* tree::insert(int ele, struct node* cur)
{
	
	if (cur == NULL)
	{
		struct node * creat;
		creat = new node;
		creat->data = ele;

		creat->left = NULL;
		creat->right = NULL;
		if(root==NULL)
		root = creat;
	
		return creat;
	}
	else
	{
		if (ele < cur->data) {
		
			cur->left = insert(ele, cur->left);
		}
		else if (ele > cur->data) {
		
			cur->right = insert(ele, cur->right);
		}
	  return cur;
	}


}
int main()
{
	tree T1;

	T1.insert(1, T1.root);

	T1.insert(2, T1.root);
	T1.insert(4, T1.root);
	T1.insert(3, T1.root);
	T1.inorder(T1.root);
	cout << T1.height(T1.root);
	getchar();
}