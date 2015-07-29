//QuickSort on a doubly linked list
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* next;
	Node* prev;
};

Node* createNewNode(int n) {
	Node* newNode = new Node;
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->info = n;
	return newNode;
}

void insertBeg(Node** head, int new_data) {
	Node* newNode = createNewNode(new_data);
	if(*head==NULL)
		*head = newNode;
	else {
		newNode->next = *head;
		(*head)->prev = newNode;
		*head = newNode;
	}
}

void printList(Node* node) {
	while(node != NULL) {
		cout<<node->info<<" -> ";
		node = node->next;
	}
}

void swap (int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

Node* partition(Node* head, Node* lastNode) {
	int x = lastNode->info;
	Node* i = head->prev;

	for(Node* j = head; j != lastNode; j = j->next) {
		if(j->info <= x) {
			if(i==NULL)
				i = head;
			else
				i = i->next;

			swap(&(i->info), &(j->info));
		}
	}
	if(i==NULL)
		i = head;
	else
		i = i->next;

	swap(&(i->info), &(lastNode->info));
	return i;
}

void QuickSort(Node* head, Node* lastNode) {
	if(lastNode != NULL && lastNode != head && lastNode != head->next) {
		Node* p = partition(head, lastNode);
		QuickSort(head, p->prev);
		QuickSort(p->next, lastNode);
	}
}

Node* lastNode(Node* root) {
	while(root && root->next)
		root = root->next;
	return root;
}

int main() {
	Node* a = NULL;
	insertBeg(&a, 5);
	insertBeg(&a, 20);
	insertBeg(&a, 4);
	insertBeg(&a, 3);
	insertBeg(&a, 30);
	printList(a);
	cout<<endl;
	Node* last = lastNode(a);
	QuickSort(a, last);
	printList(a);
	return 0;
}