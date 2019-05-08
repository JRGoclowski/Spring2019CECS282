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

	void PushBack(TData value) {
		auto newNode = std::make_unique<Node>(std::move(value));

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

	void PushFront(TData value) {
		auto newNode = std::make_unique<Node>(std::move(value));
		newNode->mNext = std::move(mHead);
		mHead = std::move(newNode);
		mSize++;
	}

	void Insert(int index, TData value) {
		if (index > (mSize - 1)) {
			std::cout << "Index not in bounds" << std::endl;
			return;
		}
		else if (index == 0) {
			PushFront(value);
			return;
		}
		else if (index == (mSize - 1)) {
			PushBack(std::move(value));
			return;
		}
		auto newNode = std::make_unique<Node>(std::move(value));
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

	void PopBack() {
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

	void PopFront() {
		Node* temp = mHead.get();
		mHead = std::move(temp->mNext);
		mSize--;
	}

	void RemoveAt(int index) {
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
		prev->mNext = std::move(temp->mNext->mNext);
		mSize--;
	}

	void Clear() {
		mHead = std::move(nullptr);
		mSize = 0;
	}

	TData& operator[](int index)
	{
		Node* temp = mHead.get();
		for (int i = 0; i < index; i++) {
			temp = temp->mNext.get();
		}
		return temp->mData;
	}

	void PrintList() const {
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
};