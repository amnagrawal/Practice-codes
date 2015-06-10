#include<iostream>
using namespace std;

struct Node{
	int info;
	Node * left;
	Node * right;
} *root, *save, *newptr, *nptr;

void Insert(Node * ptr, Node * np)
{
	if(root == NULL)
	{
		root = np;
	}
    else{
	if(np -> info < ptr -> info)
	{
		if(ptr -> left == NULL)
			ptr -> left = np;
		else
			Insert(ptr -> left, np);
	}

	if(np -> info > ptr -> info)
	{
		if(ptr -> right == NULL)
			ptr -> right = np;
		else
			Insert(ptr -> right, np);
	}
    }
	cout<<root->info;
}

Node * Create_new_node(int n)
{
	nptr = new Node;
	nptr -> left = NULL;
	nptr -> right = NULL;
	nptr -> info = n;
	return nptr;
}

void Search(Node * ptr, int item)
{
	if(item == root -> info)
	{
		cout<<"\nFound";
		return;
	}

	while(ptr != NULL)
	{
		if(item < ptr -> info)
			ptr = ptr -> left;
		else
			ptr = ptr -> right;

		if(item == ptr -> info)
		{
			cout<<"\nFound!!";
			return;
		}
	}
}

void inorder(Node * ptr)
{
    if(ptr != NULL)
	{
	    inorder(ptr -> left);
        cout<< ptr -> info;
        inorder(ptr -> right);
	}
}

void preorder(Node * ptr)
{
    if(ptr != NULL)
	{
	    cout<<ptr -> info;
        preorder(ptr -> left);
        preorder(ptr -> right);
	}
}

void postorder(Node * ptr)
{
    if(ptr != NULL)
    {
        postorder(ptr -> left);
        postorder(ptr -> right);
        cout<< ptr -> info;
    }
}


int main()
{
	int ch1, item;
	char ch2;

	root = NULL;

	do
	{
		cout<<"Enter your choice"<<endl
			<<"1.Insert"<<endl
			<<"2.Search"<<endl
			<<"3.Inorder traversal"<<endl
			<<"4.Preorder traversal"<<endl
			<<"5.Postorder traversal"<<endl;

		cin>>ch1;

		if(ch1==1)
		{
			cout<<"\nEnter the information for the new node";
			cin>>item;
			newptr = Create_new_node(item);
			Insert(root, newptr);
		}

		if(ch1 == 2)
		{
			cout<<"\nEnter the item to be searched for: ";
			cin>>item;
			Search(root, item);
		}

		if(ch1 == 3)
			inorder(root);

		if(ch1 == 4)
			preorder(root);

		if(ch1 == 5)
			postorder(root);

		cout<<"\nDo you want to continue? (y/n)";
		cin>>ch2;
	}while(ch2 == 'y');

	return 0;
}
