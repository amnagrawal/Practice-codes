#include<iostream>
using namespace std;

struct Node {

	int info;
	Node * link;
} *start, *newptr, *save, *ptr, *rear; 

Node * Create_new_node(int n)
{
	ptr = new Node;
	ptr -> info = n;
	ptr -> link = NULL;
	return ptr;
}

void Insert_beg (Node * np)
{
	if (start == NULL)
		start = rear = np;
	else
	{
		save  = start;
		start = np;
		np -> link = save;
		
	}
}

void Insert_end (Node *np)
{
	if(start == NULL)
		start = rear = np;
	else
	{
		rear -> link = np;
		rear = np;	
	}
}

void Display(Node * np)
{
	cout<<"\nThe linked list is:  ";
	while(np != NULL)
	{
		cout<<np -> info<<"->";
		np = np -> link;
	}
	cout<<"!!!\n";
}

void DelNode(int item)
{
	int flag = 0;
	if(start == NULL)
		cout<<"!!!Underflow!!!";
	else
	{
		save = start;
		ptr = save -> link;
		
		if(start -> info == item)
		{
			start = ptr;
			delete save;			
			flag = 1;
		}
		else
		{
			while(ptr -> info != item)
			{
				ptr = ptr -> link;
				save = save -> link;		
				
				if(ptr -> info == item)
				{
					if(ptr -> link== NULL)
					{
						save -> link = NULL;
						delete ptr;
						rear = save;
						flag = 1;
					}
					else
					{
						save -> link = ptr -> link;
						delete ptr;
						flag = 1;		
					}
				}
			}
		
			if (flag == 0)
				cout<<"\nItem not found";
		}
	}
}

int main()
{
	start = rear = NULL;
	int info, item, ch;
	char ch1;
	do
	{
		cout<<"Enter your choice:"<<endl
		<<"1.Insert a node in the beginning of the linked list"<<endl
		<<"2.Insert a node at the end of the linked list"<<endl
		<<"3.Delete a node containing a particular information"<<endl
		<<"4.View the linked list"<<endl;
		
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the information of the node to be added";
			cin>>info;
			newptr = Create_new_node(info);
			Insert_beg(newptr);
			Display(start);	
		}
		else	
			if(ch==2){
			cout<<"Enter the information of the node to be added";
			cin>>info;
			newptr = Create_new_node(info);
			Insert_end(newptr);
			Display(start);	
		}
		else
			if(ch==3){
			cout<<"Enter the item to be deleted";
			cin>>item;
			DelNode(item);
			Display(start);	
		}
		else
			if(ch==4){
			Display(start);	
		}
		else
			cout<<"Wrong choice!!";
		
		cout<<"Do you want to continue(y/n)";
		cin>>ch1;	
	}while(ch1 == 'y' || ch == 'Y');
	
	return 0;
}
