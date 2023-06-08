#pragma once
#include <vector>
using namespace std;

class Node;
class PriorityQueue;
struct Point;

class AStar
{
private:
	PriorityQueue* openList;  //���߿� �� ���漱�� �������� �ۼ�����. �ʹ� ���������
	vector<Node> closeList;

public:
	bool CalcRoute(Point start, Point end);
	
};

