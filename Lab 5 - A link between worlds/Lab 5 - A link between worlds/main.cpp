#include <iostream>
#include "ModernLinkedList.h"

using namespace std;

int main() {
	auto test = ModernLinkedList();
	test.PrintList();
	
	test.PushFront(1);
	test.PushFront(2);
	test.PushFront(3);
	test.PushFront(4);
	test.PushFront(5);
	test.PrintList();
	cout << test[2];
	test[2] = 50;
	test.PrintList();
	test.Clear();


	test.PushFront(5); 
	test.PrintList();
	cout << endl << test.Size() << endl;

	test.PushBack(2);
	test.PrintList();
	cout << endl << test.Size() << endl;

	test.PushFront(3);
	test.PrintList();
	cout << endl << test.Size() << endl;

	test.PushBack(4);
	test.PrintList();
	cout << endl << test.Size() << endl;

	test.Insert(2, 9);
	test.PrintList(); 
	cout << endl << endl << test.Size() << "Inserted 2 Here" << endl;

	test.Insert(4, 13);
	test.PrintList();
	cout << endl << endl << test.Size() << endl;

	test.PopFront();
	test.PrintList();
	cout << endl << endl << test.Size() << endl;

	test.RemoveAt(3);
	test.PrintList();
	cout << endl << endl << test.Size() << endl;

	test.Insert(3, 12);
	test.PrintList();
	cout << endl << endl << test.Size() << endl;

	test.RemoveAt(0);
	test.PrintList();
	cout << endl << endl << test.Size() << endl;

	test.Insert(0, 1);
	test.PrintList();
	cout << endl << test.Size() << endl;

	test.Insert(1, 15);
	test.PrintList();
	cout << endl << test.Size() << endl;

	test.Insert(15, 7);
	test.PrintList();
	cout << endl << test.Size() << endl;

	return 0;
}
