#include <iostream>
#include "ModernLinkedList.h"

using namespace std;
//Test: PushBack X, PushFront X, Insert X, PopBack, PopFront, RemoveAt, Clear
int main() {
	auto test = ModernLinkedList();
	test.PrintList();

	cout << endl << "Pushing front 1" << endl;
	test.PushFront(1);
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Pushing front 2" << endl;
	test.PushFront(2);
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Pushing Back 3" << endl;
	test.PushBack(3);
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Pushing Back 4" << endl;
	test.PushBack(4);
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Inserting 6 at Index 2" << endl;
	test.Insert(2, 6);
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Inserting 0 at Index 0" << endl;
	test.Insert(0, 0);
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Inserting 9 at Index 5 (End of List)" << endl;
	test.Insert(5, 9);
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Inserting 15 at Index 9 (Out of Bounds)" << endl;
	test.Insert(9, 15);
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Popping Back" << endl;
	test.PopBack();
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Popping Front" << endl;
	test.PopFront();
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Removing at index 3" << endl;
	test.RemoveAt(3);
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Getting Value at List[1]" << endl;
	cout << test[1] << endl;
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Reassigning Value 20 at List[1]" << endl;
	test[1] = 20;
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

	cout << "Clearing List" << endl;
	test.Clear();
	test.PrintList();
	cout << "List size: " << test.Size() << endl;
	
	cout << endl << "Pushing front 1" << endl;
	test.PushFront(1);
	test.PrintList();
	cout << "List size: " << test.Size() << endl;

}
