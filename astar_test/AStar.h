#pragma once
#include <vector>
using namespace std;

class Node;
class PriorityQueue;
struct Point;

class AStar
{
private:
	PriorityQueue* openList;  //나중에 걍 전방선언 빼버리고 작성하자. 너무 어려워질듯
	vector<Node> closeList;

public:
	bool CalcRoute(Point start, Point end);
	
};

