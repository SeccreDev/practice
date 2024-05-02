#include <iostream>
using namespace std;

// Linked List - a sequence of data structures nodes; each node containing data and a pointer to its successor node, serving as a link. The last node in the list
//               has its successor pointer set to NULL. The node at the beginning is called 'head of the list', and its just a pointer to a node without data.
//               The entire list is identified by the pointer to the first node, the pointer is called the head. The list head may have the address of the first node,
//               or may be NULL. The nodes of a linked list are usually dynamically allocated. Nodes can be added or removed from the linked list during execution.
//               Addition or removal of nodes can take place at beginning, middle or, end of the list. Insertion and removal of node in the middle of the list is efficient.
//				 Each node contains: data() and a pointer that can point to another node. Head pointer initialized to NULL indicates an empty list (list with no nodes)
struct Node
{
	int data;  // The data held by the node
	Node *next;  // a pointer to the address of the next NODE

	//Constructor
	Node(int d = 0, Node* n = NULL)
	{
		data = d;
		next = n;
	}
};

int main()
{
	Node* head = NULL;  // creates an empty linked list!
	Node* traversal = NULL;

	head = new Node(50, head);
	head = new Node(54, head);
	head = new Node(984, head);
	head = new Node(651, head);
	head = new Node(498, head);

	traversal = head;
	while (traversal != NULL)
	{
		cout << traversal->data << " --> ";
		traversal = traversal->next;
	}
	cout << "NULL (End of List)";



	return 0;
}