#pragma once
#include <vector>
using namespace std;

class Node;

class PriorityQueue
{
public:
	vector<Node*> heap;
	PriorityQueue();
	~PriorityQueue();

public:
	int Count();
	Node* FindNode(Node& n);
	void Push(Node data);
	Node* Pop();


	void PrintHeap();
};

