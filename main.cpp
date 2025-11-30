#include "List.h"
int main()
{
	// testing my code
	List l1;
	l1.insertEnd(1,'A');
	l1.insertEnd(2,'B');
	l1.insertEnd(3,'C');
	l1.insertEnd(4,'D');
	l1.insertEnd(5,'E');
	l1.traverse();
	//	key: 1 - data A
	//	key: 2 - data B
	//	key: 3 - data C
	//	key: 4 - data D
	//	key: 5 - data E
	return 0;
}
