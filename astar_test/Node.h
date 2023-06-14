#pragma once
#include <string>

using namespace std;
struct Point;

class Node
{
public:
	Node(int x, int y, float G, float F);
	~Node();
	Node(const Node& other);  //���� ������
	Node& operator = (const Node& other); //���� ����

	Point* point;

	float G;
	float F;

	Node* parent;  //�θ� ������

public:
	int Compare(Node* other);

	string ToString();
};

