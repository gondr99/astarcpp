#pragma once
#include <vector>
#include "Common.h"
using namespace std;


class Node;
class PriorityQueue;

class AStar
{
private:
	PriorityQueue* openList;  //나중에 걍 전방선언 빼버리고 작성하자. 너무 어려워질듯
	vector<Node*> closeList;
	vector<Point> routePath;
	Point destination;

public:
	bool CalcRoute(Point start, Point end);
	void FindOpenList(Node* currentNode);
	float CalcH(Point pos);
	void PrintRoute();
};

