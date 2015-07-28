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
	if(*head == NULL)
		*head = newNode;
	else {
		newNode->next = *head;
		*head = newNode;
	}
}

void printList(Node* node) {
	while(node != NULL) {
		cout<< node->info <<"->";
		node = node->next;
	}
}

Node* sortedMerge(Node* a, Node* b) {
	Node* result = NULL;

	if(a == NULL)
		return b;
	else if(b==NULL)
		return a;

	if(a->info < b->info) {
		result = a;
		result->next = sortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = sortedMerge(a, b->next);
	}

	return result;
}

void split(Node* source, Node** front, Node** back) {
	Node* fast;
	Node* slow;

	//for cases where length is less than 2
	if((source == NULL) || (source->next == NULL)) {
		*front = source;
		*back = NULL;
	}
	else {
		slow = source;
		fast = source->next;

		//Advance fast by 2 nodes, and slow by 1 node
		while(fast != NULL) {
			fast = fast->next;
			if(fast != NULL) {
				fast = fast->next;
				slow = slow->next;
			}
		}

		//slow now is before the midpt of the list
		*front = source;
		*back = slow->next;
		slow->next = NULL;
	}
}

//sorts the linked list by changing the next ptrs (not data)
void msort(Node** head) {
	Node* temp = *head;
	Node* a;
	Node* b;

	//when the length of the list is 0 or 1
	if((temp == NULL) || (temp->next == NULL))
		return;

	split(temp, &a, &b);

	msort(&a);
	msort(&b);

	*head = sortedMerge(a, b);
}

int main() {
	Node* a = NULL;

	insertBeg(&a, 15);
	insertBeg(&a, 10);
	insertBeg(&a, 5);
	insertBeg(&a, 20);
	insertBeg(&a, 3);
	insertBeg(&a, 2);
	printList(a);
	cout<<endl;
	msort(&a);
	printList(a);
	return 0;
}