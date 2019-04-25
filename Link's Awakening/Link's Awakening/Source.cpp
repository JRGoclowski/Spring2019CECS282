#include "TemplateLinkedList.h"
#include <string>
using namespace std;



int main(int, char*[]) {
	TemplateLinkedList<int> intList = TemplateLinkedList<int>();
	TemplateLinkedList<string> stringList = TemplateLinkedList<string>();
	TemplateLinkedList<unique_ptr<string>> ptrList = TemplateLinkedList<unique_ptr<string>>();

	cout << "Pushing 10 to int list to back " << endl;
	intList.PushBack(10);
	cout << "Pushing 5 to int list to front" << endl;
	intList.PushFront(5);
	cout << "Pushing 1 to int list to back " << endl;
	intList.PushBack(1);
	cout << "Pushing 5 to int list to front" << endl;
	intList.PushFront(5);
	intList.PrintList();

	cout << "Pushing \"Hello \" to string list in back" << endl;
	stringList.PushBack("Hello");
	cout << "Pushing \"World\" to string list in back" << endl;
	stringList.PushBack("World");
	cout << "Pushing \"I say, \" to string list in front" << endl;
	stringList.PushFront("I say, ");
	cout << "Pushing \"Joyously \" to string list in front" << endl;
	stringList.PushFront("Joyously ");
	stringList.PrintList();

	cout << "Pushing pointer to \" to \" to pointer list in front" << endl;
	ptrList.PushFront(make_unique<string>(" to "));
	cout << "Pushing pointer to \"Pointed\" to pointer list in front" << endl;
	ptrList.PushFront(make_unique<string>("Pointed"));
	cout << "Pushing pointer to \"String\" to pointer list in back" << endl;
	ptrList.PushBack(make_unique<string>("String"));
	ptrList.PrintList();

	cout << "Inserting 3 to int list to index 2" << endl;
	intList.Insert(2, 3);
	intList.PrintList();

	cout << "Inserting \"Beautiful \" to string list to index 3" << endl;
	stringList.Insert(3, "Beautiful ");
	stringList.PrintList();

	cout << "Inserting \"this \" to pointer list to index 2" << endl;
	ptrList.Insert(2, make_unique<string>("this"));
	ptrList.PrintList();

	cout << "Getting [1] in each list" << endl;
	cout << intList[1] << ", " << stringList[1] << ", " << ptrList[1] << endl;

	cout << "Removing at [1] from int list, then string list, then pointer list";
	intList.RemoveAt(1);
	intList.PrintList();
	stringList.RemoveAt(1);
	stringList.PrintList();
	ptrList.RemoveAt(1);
	ptrList.PrintList();

	cout << "Removing first from int list, then string list, then pointer list";
	intList.PopFront();
	intList.PrintList();
	stringList.PopFront();
	stringList.PrintList();
	ptrList.PopFront();
	ptrList.PrintList();

	cout << "Removing Last from int list, then string list, then pointer list";
	intList.PopBack();
	intList.PrintList();
	stringList.PopBack();
	stringList.PrintList();
	ptrList.PopBack();
	ptrList.PrintList();

}