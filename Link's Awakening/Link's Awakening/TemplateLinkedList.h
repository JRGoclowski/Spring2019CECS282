#pragma once
#include <memory>
#include <iostream>

template <typename TData>
class TemplateLinkedList {
private:
	class Node {
		// A Node contains a piece of data, and *owns* a link to the next Node.
		TData mData;
		std::unique_ptr<Node> mNext;
		friend class TemplateLinkedList;

	public:
		Node(TData data) : mData(std::move(data)) { }

		// For proof that Nodes are being destroyed without us "deleting" them.
		~Node() { std::cout << "Deleting Node of data " << mData << std::endl; }
	};

	std::unique_ptr<Node> mHead;
	int mSize;

public:
	TemplateLinkedList() : mSize(0) {}
	inline int Size() const { return mSize; };

	// Methods to insert new data.
	// Adds a new "last" item.
	void PushBack(TData value);
	// Adds a new "first" item.
	void PushFront(TData value);
	// Adds a new item at the given index, so that the given value can be retrieved at that index.
	// All values that that index or larger are "moved back" by 1.
	void Insert(int index, TData value);

	// Methods to remove data.
	// Remove the "last" item.
	void PopBack();
	// Remove the "first" item.
	void PopFront();
	// Remove the item at the given index.
	void RemoveAt(int index);
	// Removes ALL data from the list, resetting it to be empty.
	void Clear();


	// Retrieves the data item at the given index, by walking the list to that position
	// and returning the data in the Node at that index. Can also be used to "set" the value
	// at the given index, if that index exists.
	TData& operator[](int index);


	// Prints the entire list for debugging.
	void PrintList() const;

};


template<typename TData>
void TemplateLinkedList<TData>::PushBack(TData value) {
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

template <typename TData>
void TemplateLinkedList<TData>::PushFront(TData value) {
	auto newNode = std::make_unique<Node>(value);
	// Any time we change a link, we must use std::move.
	newNode->mNext = std::move(mHead);

	// Transfer ownership of this new head node to the List object.
	mHead = std::move(newNode);

	// Increase the size by 1.
	mSize++;
}

template <typename TData>
void TemplateLinkedList<TData>::Insert(int index, TData value) {
	if (index > (mSize - 1)) {
		std::cout << "Index not in bounds" << std::endl;
		return;
	}
	else if (index == 0) {
		TData addition = std::move(value);
		PushFront(addition);
		return;
	}
	else if (index == (mSize - 1)) {
		TData addition = std::move(value);
		PushBack(addition);
		return;
	}
	auto newNode = std::make_unique<Node>(value);
	Node* prev = mHead.get();
	Node* temp = mHead.get();
	for (int i = 0; i < index - 1; i++) {
		temp = temp->mNext.get();
	}
	prev = temp;
	newNode->mNext = std::move(temp->mNext);
	prev->mNext = std::move(newNode);
	mSize++;

}

template <typename TData>
void TemplateLinkedList<TData>::PopBack() {
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

template <typename TData>
void TemplateLinkedList<TData>::PopFront() {
	Node* temp = mHead.get();
	mHead = std::move(temp->mNext);
	mSize--;
}

template <typename TData>
void TemplateLinkedList<TData>::RemoveAt(int index) {
	if (index > (mSize - 1)) {
		std::cout << "Index not in bounds" << std::endl;
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
	Node* prev = mHead.get();
	Node* temp = mHead.get();
	for (int i = 0; i < index - 1; i++) {
		temp = temp->mNext.get();
	}
	prev = temp;
	prev->mNext= std::move(temp->mNext->mNext);
	mSize--;
}

template <typename TData>
void TemplateLinkedList<TData>::Clear() {
	mHead = std::move(nullptr);
	mSize = 0;
}

template <typename TData>
TData& TemplateLinkedList<TData>::operator[](int index)
{
	Node* temp = mHead.get();
	for (int i = 0; i < index; i++) {
		temp = temp->mNext.get();
	}
	return temp->mData;
}

template <typename TData>
void TemplateLinkedList<TData>::PrintList() const {
	// To walk this list, we need to create a temp that points to the head node, and then gets moved
	// to the next, to the next, etc. This temp does not want to claim ownership of any of these nodes,
	// so it can't be a unique_ptr. A "raw" Node pointer will let us "use" each Node's values without
	// having to be an owner of that memory.

	std::cout << "[";
	Node* temp = mHead.get(); // reminder: a unique_ptr's .get() gives us back the raw pointer.
	// As long as the Node that temp points to is not null.
	while (temp != nullptr) {
		if (temp != mHead.get()) {
			// Separate each element with a comma.
			std::cout << ", ";
		}
		std::cout << temp->mData;
		temp = temp->mNext.get();
	}
	std::cout << "]" << std::endl;
}