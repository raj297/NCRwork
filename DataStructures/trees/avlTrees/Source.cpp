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
	struct node* insert(int ele, struct node*);
	void inorder(struct node*);
	int height(struct node *);
	struct node* l_rotation(struct node * cur);
	struct node* r_rotation(struct node * cur);
	struct node* lr_rotation(struct node * cur);
	struct node* rl_rotation(struct node * cur);
	struct node* balance(struct node * cur);
	int balFac(struct node*);
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
		if (root == NULL)
			root = creat;

		return creat;
	}
	else
	{
		if (ele < cur->data) {

			cur->left = insert(ele, cur->left);
		balance(cur);
		}
		else if (ele > cur->data) {

			cur->right = insert(ele, cur->right);
		balance(cur);
		}
		return cur;
	}


}
struct node* tree::l_rotation(struct node * cur) {

	struct node * temp;
	temp = cur->right;
	cur->right = temp->left;
	 temp->left=cur;

	 return temp;
}
struct node* tree::r_rotation(struct node * cur) {

	struct node * temp;
	temp = cur->left;
	cur->left = temp->right;
	temp->right = cur;

	return temp;

}
struct node* tree::lr_rotation(struct node * cur) {
	struct node * temp=cur->left;
	temp=l_rotation(temp);
	cur = r_rotation(temp);
	return cur;
}
struct node* tree::rl_rotation(struct node * cur) {
	struct node * temp=cur->right;
	temp = r_rotation(temp);
	cur = l_rotation(temp);
	return cur;
}
struct node* tree::balance(struct node * cur)
{
	if (balFac(cur) > 1)
	{
		if (balFac(cur->left) == 1)
			cur= r_rotation(cur);
		else
			cur = lr_rotation(cur);

	
	}

	 if (balFac(cur) < -1)
	{
		if (balFac(cur->right) == 1)
			cur = rl_rotation(cur);
		else
			cur = l_rotation(cur);

	}
	
		return cur;
}
int tree:: balFac(struct node *cur)
{
	return (height(cur->left) - height(cur->right));
}
int main()
{
	tree T1;

	T1.insert(1, T1.root);

	T1.insert(2, T1.root);
	T1.insert(4, T1.root);
	T1.inorder(T1.root);
	//T1.insert(3, T1.root);
	//T1.inorder(T1.root);
	//cout << T1.height(T1.root)<<T1.balFac(T1.root);
	getchar();
}