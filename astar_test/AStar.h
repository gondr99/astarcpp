#pragma once
#include <vector>
#include "Common.h"
using namespace std;


class Node;
class PriorityQueue;

class AStar
{
private:
	PriorityQueue* openList;  //���߿� �� ���漱�� �������� �ۼ�����. �ʹ� ���������
	vector<Node*> closeList;
	vector<Point> routePath;
	Point destination;

public:
	bool CalcRoute(Point start, Point end);
	void FindOpenList(Node* currentNode);
	float CalcH(Point pos);
	void PrintRoute();
};

