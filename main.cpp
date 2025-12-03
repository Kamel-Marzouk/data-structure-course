#include "List.h"
using namespace std;

// Receive a list and to return how many of the nodes contain zeros in the data field.
int countZeros(List &l)
{
	int d, count = 0;
	if (!l.listIsEmpty())
	{
		l.toFirst();
		while (!l.curIsEmpty())
		{
			d = l.retrieveKey();
			if (d == 0)
				count++;
			l.advance();
		}
		return count;
	}
};

// Receive a list and to return the sum of data stored in the list.
int dataSum(List &l)
{
	int sum = 0;
	if (!l.listIsEmpty())
	{
		l.toFirst();
		while (!l.curIsEmpty())
		{
			sum += l.retrieveKey();
			l.advance();
		}
		return sum;
	}
};

// Receive a list (L) and to split it into two separate lists, returning two new lists (L1) containing positive data numbers and (L2) containing negative data numbers. After the split, (L) will become empty.
void splitList(List &l)
{
	List nl, pl;
	if (!l.listIsEmpty())
	{
		l.toFirst();
		while (!l.curIsEmpty())
		{
			if (l.retrieveKey() >= 0)
				pl.insertEnd(l.retrieveKey(), l.retrieveData());
			else
				nl.insertEnd(l.retrieveKey(), l.retrieveData());
			l.deleteNode(); // l.advance();
		}
		// l.makeListEmpty();
	}
	cout << "Positive list : " << endl;
	pl.traverse();
	cout << "Negative list : " << endl;
	nl.traverse();
}

// Receive a list and to return how many of the nodes contain even numbers in the key field.
int evenKeys(List &l)
{
	int evenCount = 0;
	if (!l.listIsEmpty())
	{
		l.toFirst();
		while (!l.curIsEmpty())
		{
			if (l.retrieveKey() % 2 == 0)
				evenCount++;
			l.advance();
		}
		return evenCount;
	}
}

// Receive two lists (L1) and (L2) and append (L2) to the end of (L1), returning the result in a new list (L) without changing the original lists.
void appendLists(List &L, List &L1, List &L2)
{
	int key;
	char data;

	if (!L1.listIsEmpty() && !L2.listIsEmpty())
	{
		L1.toFirst();
		while (!L1.curIsEmpty())
		{
			L1.retrieveAllData(key, data);
			L.insertEnd(key, data); // L.insertEnd(L1.retrieveKey(),L1.retrieveData());
			L1.advance();
		}
		L2.toFirst();
		while (!L2.curIsEmpty())
		{
			L2.retrieveAllData(key, data);
			L.insertEnd(key, data); // L.insertEnd(L2.retrieveKey(),L2.retrieveData());
			L2.advance();
		}
	}
}

// main function
int main()
{
	// testing my code
	List l;
	l.insertEnd(0, 'A');
	l.insertEnd(1, 'B');
	l.insertEnd(2, 'C');
	l.insertEnd(3, 'D');
	l.insertEnd(4, 'E');
	l.insertEnd(-7, 'f');
	l.insertEnd(-15, 'g');
	//	l.traverse();
	//	key: 1 - data A
	//	key: 2 - data B
	//	key: 3 - data C
	//	key: 4 - data D
	//	key: 5 - data E
	//	cout << "the sumition of data = " << dataSum(l) << endl;
	//	cout << "the numbers of zeros is : " << countZeros(l) << endl;
	// check list before split and delete it's items
	//	cout << l.listIsEmpty() << endl;
	//	splitList(l);
	// check list after spliting and delete it's items
	//	cout << l.listIsEmpty() << endl;

	// recursive list size
	// cout << "Numbers of nodes in L = " << l.recursiveListSize() << " Nodes" << endl;
	// l.displayList();
	// cout << "Even Counter = " << evenKeys(l);
	List originList, L1, L2;
	L1.insertEnd(0, 'A');
	L1.insertEnd(1, 'B');
	L1.insertEnd(2, 'C');
	L1.insertEnd(3, 'D');
	L2.insertEnd(4, 'E');
	L2.insertEnd(-7, 'f');
	L2.insertEnd(-15, 'g');
	appendLists(originList, L1, L2);
	originList.traverse();
	return 0;
}
