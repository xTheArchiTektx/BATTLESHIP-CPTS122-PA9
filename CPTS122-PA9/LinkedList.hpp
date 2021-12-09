#pragma once
#include "PA9.hpp"



template<typename LList>
class ListNode
{
public:
	ListNode() {};
	ListNode(LList data)
	{
		mData = data;
		nextNode = nullptr;
	}
	~ListNode() {};
	
	ListNode* getNext(void) { return nextNode; };
	LList getData(void) { return mData; };
	ListNode<LList>* makeNode(LList newData)
	{
		return new ListNode(newData);
	}
	void setNext(ListNode<LList>* newNext) { nextNode = newNext; };
	void setData(LList newData) { mData = newData; }
private:
	ListNode<LList>* nextNode;
	LList mData;

};

template<typename LList>
class LinkedList
{
public:
	LinkedList(void)
	{
		mpHead = nullptr;
	}
	~LinkedList(void) {};
	ListNode<LList>* getHead(void) { return mpHead; };
	void insert(ListNode<LList>* newNode)
	{
		newNode->setNext(newNode);
		mpHead = newNode;
	}
private:
	ListNode<LList>* mpHead;
};
