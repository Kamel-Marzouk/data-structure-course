#include <iostream>
using namespace std;
class List
{
	// data members
	class node
	{
	public:
		int key;
		char data;
		node *next;
	};
	typedef node *NodePointer;
	NodePointer head, prev, cursor; // pointers
	int r_list_size(NodePointer h);
	int display(NodePointer h);

public:
	// function mempers
	List();
	bool listIsEmpty();	   // return True if list is empty
	bool curIsEmpty();	   // return True if current position is empty
	void toFirst();		   // to make the current node the first node; if list is empty, the current position is still empty
	bool atFirst();		   // to return True if the current node is the first node or if the list and the current position are both empty.
	void advance();		   // to advance to next node. Assume the current position is nonempty initially.
	void toEnd();		   // to make the current node the tail node; if list is empty, the current position is still empty
	int listSize();		   // to return the size of the list
	void updateData(char); // to update the data portion of the current node to contain d; assume the current position is nonempty.
	void updateKey(int);
	char retrieveData(); // to return the data in the current node; assume the current position is nonempty.
	int retrieveKey();
	void retrieveAllData(int &, char &);
	void insertFirst(int, char);	 // insert a node with key (k) and data (d) at the head of the list; the new node becomes the current node.
	void insertAfter(int, char);	 // insert a node after the current node without changing the current position; assume the current position is nonempty in a non-empty list.
	void insertBefore(int, char);	 // insert a node before the current node ; current position becomes the new node
	void insertEnd(int, char);		 // insert a node at the end of the list, current position becomes the new node.
	void deleteNode();				 // delete the current node and set the current position to the next node; if the current node is the last node initially, the current position becomes empty; assume the current position is nonempty initially.
	void deleteFirst();				 // delete the first node and set the current position to the next node; if it was initially the only node, the current position becomes empty;
	void deleteEnd();				 // delete the last node and set the current position to empty.
	void makeListEmpty();			 // delete whole list
	bool search(int);				 // search the list for the node with key part that matches (k). If found, set cursor to the node and return True, else return false and the current position becomes empty.
	void orderInsert(int k, char d); // insert a node in a position that maintains an ascending order of the key portion of the nodes.
	void traverse();				 //  traverse list to print key and info fields.
	int recursiveListSize();		 // A public function .Recursive_List_Size( ) to call a recursive private function to return the size of the list.
	int displayList();				 // Implement a public function .DisplayList( ) to call a recursive private function to display the contents of the nodes in the list
};
