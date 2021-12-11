#pragma once 
#include "PA9.hpp"

class CordListNode
{
public:
	//constructor
	CordListNode()
	{
		xAxis = 0;
		yAxis = 0;
		mpNextPtr = nullptr;
	}
	
	//Destructor
	~CordListNode() {};

	//cpy constructor
	CordListNode(CordListNode& newNode) {
		xAxis = newNode.xAxis;
		yAxis = newNode.yAxis;
		mpNextPtr = newNode.mpNextPtr;
	}

	CordListNode(int newX, int newY) {
		xAxis = newX;
		yAxis = newY;
		mpNextPtr = nullptr;
	}

	//Setters
	void setY(int newY) { yAxis = newY; };
	void setX(int newX) { xAxis = newX; };
	void setNxt(CordListNode* newNext) { mpNextPtr = newNext; }

	//getters
	int getX(void) { return xAxis; };
	int getY(void) { return yAxis; };
	CordListNode* getNext(void) { return mpNextPtr; };
private:
	int xAxis;
	int yAxis;
	CordListNode* mpNextPtr;
};

class ShipCordList
{
public:
	typedef enum direction
	{
		Left, Right, Up, Down
	}Direction;

	//constructor 
	ShipCordList() {
		mpHead = new CordListNode;
		listSize = 0;
	};

	//Cpy Constructor
	ShipCordList(ShipCordList& newList)
	{
		mpHead = newList.mpHead;
		listSize = newList.listSize;
	}

	//destructor
	~ShipCordList() {};

	//setters
	void setHeadPtr(CordListNode* newNode) { mpHead = newNode; };
	void setSize(int newSize) { listSize = newSize; };

	//Getters
	CordListNode* getHead(void) { return mpHead; };
	int getSize(void) { return listSize; };

	//Member Functions
	void insert(CordListNode* newNode) 
	{
		newNode->setNxt(mpHead);
		mpHead = newNode;
		listSize++;
	}

private:
	CordListNode* mpHead;
	int listSize;
};