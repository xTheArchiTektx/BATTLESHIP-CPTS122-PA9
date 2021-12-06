#pragma once 
#include "PA9.hpp"

class CordListNode
{
public:
	//constructor
	CordListNode();
	//cpy constructor
	~CordListNode();
	CordListNode(CordListNode& newNode);
	//Destructor
	//Setters
	void setY(int newY) { yAxis = newY; };
	void setX(int newX) { xAxis = newX; };
	void setNxt(CordListNode* newNext) { mpNextPtr = new CordListNode; }

	//getters
	int getX(void);
	int getY(void);
	CordListNode* getNext(void);

private:
	int xAxis;
	int yAxis;
	CordListNode* mpNextPtr;
};