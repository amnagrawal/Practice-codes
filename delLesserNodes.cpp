//Deletes nodes in a ll which have a lesser value in the right side
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* next;
};

Node* createNewNode(int n) {
	Node* newNode = new Node;
	newNode->next = NULL;
	newNode->info = n;
	return newNode;
}

void insertBeg(Node** head, int new_data) {
	Node* newNode = createNewNode(new_data);
	if(*head==NULL)
		*head = newNode;
	else {
		newNode->next = *head;
		*head = newNode;
	}
}

void printList(Node* node) {
	while(node != NULL) {
		cout<<node->info<<" -> ";
		node = node->next;
	}
}

void reverseList(Node** head) {
	Node* current = *head;
	Node* prev = NULL;
	Node* next;

	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
}

void delNode(Node* head) {
	Node* current = head;
	Node* maxNode = head;
	Node* temp;

	while(current != NULL && current->next != NULL) {
		if(current->next->info < maxNode->info) {
			temp = current->next;
			current->next = temp->next;
			delete temp;
		}
		else {
			current = current->next;
			maxNode = current;
		}
	}
}

void delLesserNodes(Node** head) {
	reverseList(head);

	delNode(*head);

	reverseList(head);
}

int main() {
	Node* a  = NULL;

	insertBeg(&a, 3);
	insertBeg(&a, 2);
	insertBeg(&a, 6);
	insertBeg(&a, 5);
	insertBeg(&a, 11);
	insertBeg(&a, 10);
	insertBeg(&a, 15);
	insertBeg(&a, 12);
	printList(a);
	cout<<endl;
	delLesserNodes(&a);

	printList(a);

	return 0;
}