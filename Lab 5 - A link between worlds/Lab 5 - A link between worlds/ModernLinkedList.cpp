#include "ModernLinkedList.h"
#include <memory>
#include <iostream>
using namespace std;


//TESTED: PASS
void ModernLinkedList::PushBack(int value) {
	auto newNode = std::make_unique<Node>(value);

	if (mSize == 0) {
		mHead = std::move(newNode);
		mSize++;
	}
	else {

		Node* temp = mHead.get();
		while (temp->mNext != nullptr) {
			temp = temp->mNext.get();
		}

		temp->mNext = std::move(newNode);
		mSize++;
	}

}

void ModernLinkedList::PushFront(int value) {
	auto newNode = std::make_unique<Node>(value);
	// Any time we change a link, we must use std::move.
	newNode->mNext = std::move(mHead);

	// Transfer ownership of this new head node to the List object.
	mHead = std::move(newNode);

	// Increase the size by 1.
	mSize++;
}

void ModernLinkedList::Insert(int index, int value) {
	if (index > (mSize - 1)) {
		cout << "Index not in bounds" << endl;
		return;
	}
	else if (index == 0) {
		PushFront(value);
		return;
	}
	else if (index == (mSize - 1)) {
		PushBack(value);
		return;
	}
	auto newNode = std::make_unique<Node>(value);
	Node *prev = mHead.get();
	Node *temp = mHead.get();
	for (int i = 0; i < index-1; i++) {
		temp = temp->mNext.get();
	}
	prev = temp;
	newNode->mNext = std::move(temp->mNext);
	prev->mNext = std::move(newNode);
	mSize++;

}

void ModernLinkedList::PopBack() {
	if (mSize == 1) {
		// Set head to nullptr, which destroys the only remaining node.
		// Reminder: to change ownership, use std::move.
		mHead = std::move(nullptr);
		mSize = 0;
	}
	else {
		// First walk to the second-to-last node in the list.
		// See PrintList().
		Node* temp = mHead.get();
		while (temp->mNext->mNext != nullptr) {
			temp = temp->mNext.get();
		}
		
		// If temp's next's next is null, then temp is the second to last node.
		// temp's next must now be set to null, which will destroy what used to be last.
		temp->mNext = std::move(nullptr);
		mSize--;
	}
}

void ModernLinkedList::PopFront() {
	Node *temp = mHead.get();
	mHead = std::move(temp->mNext);
	mSize--;
}

void ModernLinkedList::RemoveAt(int index) {
	if (index > (mSize - 1)) {
		cout << "Index not in bounds" << endl;
		return;
	}
	else if (index == 0) {
		PopFront();
		return;
	}
	else if (index == (mSize - 1)) {
		PopBack();
		return;
	}
	Node *prev = mHead.get();
	Node *temp = mHead.get();
	for (int i = 0; i < index - 1; i++) {
		temp = temp->mNext.get();
	}
	prev = temp;
	prev->mNext = std::move(temp->mNext->mNext);
	mSize--;
}

void ModernLinkedList::Clear() {
	mHead = std::move(nullptr);
	mSize = 0;
}

int & ModernLinkedList::operator[](int index)
{
	Node *temp = mHead.get();
	for (int i = 0; i < index; i++) {
		temp = temp->mNext.get();
	}
	return temp->mData;
}

void ModernLinkedList::PrintList() const {
	// To walk this list, we need to create a temp that points to the head node, and then gets moved
	// to the next, to the next, etc. This temp does not want to claim ownership of any of these nodes,
	// so it can't be a unique_ptr. A "raw" Node pointer will let us "use" each Node's values without
	// having to be an owner of that memory.

	cout << "[";
	Node* temp = mHead.get(); // reminder: a unique_ptr's .get() gives us back the raw pointer.
	// As long as the Node that temp points to is not null.
	while (temp != nullptr) {
		if (temp != mHead.get()) {
			// Separate each element with a comma.
			cout << ", ";
		}
		cout << temp->mData;
		temp = temp->mNext.get();
	}
	cout << "]" << endl;
}