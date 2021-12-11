#pragma once
#include "PA9.hpp"



template<class LList>
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
		return new ListNode<LList>(newData);
	}
	void setNext(ListNode<LList>* newNext) { nextNode = newNext; };
	void setData(LList newData) { mData = newData; }
private:
	ListNode<LList>* nextNode;
	LList mData;

};

template<class LList>
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
		newNode->setNext(mpHead);
		mpHead = newNode;
	}
private:
	ListNode<LList>* mpHead;
};
