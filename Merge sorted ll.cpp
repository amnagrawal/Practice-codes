//Using a dummy node

#include <iostream>
#include <cassert>
using namespace std;

struct Node
{
	int info;
	Node * next;
} *tail; //tail is the dummy node of the merged list which points to its last element

Node * createNewNode(int n) {
	Node * ptr = new Node;
	ptr -> next = NULL;
	ptr -> info = n;
	return ptr;
}

void insertBeg(Node **head, int new_data) {
	Node * newNode = createNewNode(new_data);
	if(*head == NULL){
		*head = newNode;
	}
	else {
		newNode -> next = *head;
		*head = newNode;
	}
}

void printList(Node *node) {
	while(node != NULL) {
		cout<< node -> info <<" -> ";
		node = node -> next;
	}
}

void moveNode(Node **source, Node **dest) {
	Node *temp = *source;
	assert(temp != NULL);

	*source = (*source) -> next; //Advance the source ptr
	temp -> next = *dest; //Link the old ptr to the dest
	*dest = temp; //Make dest point to the new node
}

Node* mergeSorted(Node *a, Node *b) {
	Node dummy; //A dummy first node
	Node *tail = &dummy;

	dummy.next = NULL;
	while(1) {
		if (a==NULL) {
			/*If either of the list runs out, then simply move the other list*/
			tail->next = b;
			break;
		}
		else if(b==NULL) {
			tail->next = a;
			break;
		}

		if (a->info <= b->info) {
			moveNode(&a, &(tail->next));
		}
		else
			moveNode(&b, &(tail->next));

		tail = tail->next;
	}

	return dummy.next;
}

int main() {
	Node *a = NULL;
	Node *b = NULL;

	insertBeg(&a, 12);
	insertBeg(&a, 10);
	insertBeg(&a, 5);

	insertBeg(&b, 13);
	insertBeg(&b, 9);
	insertBeg(&b, 6);
	printList(a);
	cout<<endl;
	printList(b);
	cout<<endl;
	Node *res = mergeSorted(a, b);
	printList(res);
	//getchar();
	return 0;
}