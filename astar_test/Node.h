#pragma once
#include <string>

using namespace std;
struct Point;

class Node
{
public:
	Node(int x, int y, float G, float F);
	~Node();
	Node(const Node& other);  //복사 생성자
	Node& operator = (const Node& other); //복사 대입

	Point* point;

	float G;
	float F;

	Node* parent;  //부모 포인터

public:
	int Compare(Node* other);

	string ToString();
};

