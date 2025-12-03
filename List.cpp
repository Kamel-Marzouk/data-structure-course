// functions implementation
#include "List.h"

List::List()
{
	head = prev = cursor = NULL;
}

bool List::listIsEmpty()
{
	/*if(head == NULL)
		return true;
	else
		return flase;*/
	return (head == NULL);
}

bool List::curIsEmpty()
{
	return (cursor == NULL);
}

void List::toFirst()
{
	cursor = head;
}

bool List::atFirst()
{
	// to return True if the current node is the first node or
	// if the list and the current position are both empty.
	if (listIsEmpty())
	{
		if (curIsEmpty())
			return true;
		else
			return false;
	}
	else
	{
		return (cursor == head);
	}
}

void List::advance()
{
	prev = cursor;
	cursor = cursor->next;
}

void List::toEnd()
{
	if (!listIsEmpty())
	{
		toFirst();
		while (cursor->next != NULL)
			advance();
	}
}

int List::listSize()
{
	node *p;
	int count = 0;
	if (!listIsEmpty())
	{
		toFirst();
		p = cursor;
		while (cursor->next != NULL)
		{
			count++;
			p = p->next;
		}
	}
	return count;
}

void List::updateData(char d)
{
	cursor->data = d;
}

void List::updateKey(int k)
{
	cursor->key = k;
}

char List::retrieveData()
{
	return cursor->data;
}

int List::retrieveKey()
{
	return cursor->key;
}

void List::retrieveAllData(int &k, char &d)
{
	k = cursor->key;
	d = cursor->data; // return cursor->data
}

void List::insertFirst(int k, char d)
{
	NodePointer p = new node;
	p->key = k;
	p->data = d;
	p->next = head;
	head = p;
	cursor = head; // toFirst()
	prev = NULL;
}

void List::insertAfter(int k, char d)
{
	NodePointer p = new node;
	p->key = k;
	p->data = d;

	p->next = cursor->next;
	cursor->next = p;
	prev = cursor; // OR prev = prev-> next;
	cursor = p;	   // OR cursor = cursor-> next;
}

void List::insertBefore(int k, char d)
{
	NodePointer p = new node;
	p->key = k;
	p->data = d;

	p->next = cursor; // OR p->next = prev->next;
	prev->next = p;
	cursor = p;
}

void List::insertEnd(int k, char d)
{
	if (listIsEmpty())
		insertFirst(k, d);
	else
	{
		toEnd();
		insertAfter(k, d);
	}
}

void List::deleteNode()
{
	NodePointer p;
	p = cursor;
	if (!curIsEmpty())
	{
		if (atFirst())
		{
			cursor = cursor->next;
			head = cursor;
			delete p;
		}
		else
		{
			cursor = cursor->next;
			prev->next = cursor;
			delete p;
		}
	}
}

void List::deleteFirst()
{
	if (!listIsEmpty())
	{
		toFirst();
		deleteNode();
	}
}

void List::deleteEnd()
{
	if (!listIsEmpty())
	{
		toEnd();
		deleteNode();
	}
}

void List::makeListEmpty()
{
	//	toFirst();
	//	while(!listIsEmpty())
	//		deleteNode();

	//	if(!listIsEmpty())
	//	{
	//		toFirst();
	//		while(!listIsEmpty())
	//		{
	//			NodePointer p;
	//			p= cursor;
	//			cursor = cursor-> next;
	//			delete p;
	//		}
	//	}

	if (!listIsEmpty())
	{
		toFirst();
		while (cursor != NULL)
		{
			NodePointer p;
			p = cursor;
			cursor = cursor->next;
			delete p;
		}
		head = NULL;
		prev = NULL;
	}
}

bool List::search(int k)
{
	toFirst();
	bool found = false;
	while ((!found) && (cursor != NULL))
	{
		if (k == cursor->key)
			found = true;
		else
			advance();
	}
	return found;
}

void List::orderInsert(int k, char d)
{
	toFirst();
	while ((cursor != NULL) && (k > cursor->key))
		advance();
	if (prev == NULL)
		insertFirst(k, d);
	else
		insertBefore(k, d);
}

void List::traverse()
{
	toFirst();
	while (!curIsEmpty())
	{
		cout << "key: " << cursor->key << " - data " << cursor->data << endl;
		advance();
	}
}

int List::r_list_size(NodePointer h)
{
	if (h == NULL)
		return 0;
	return 1 + r_list_size(h->next);
}

int List::recursiveListSize()
{
	return r_list_size(head);
}

int List::display(NodePointer h)
{
	if (h == NULL)
		return 0;
	cout << "key: " << h->key << " - data " << h->data << endl;
	display(h->next);
}

int List::displayList()
{
	return display(head);
}
