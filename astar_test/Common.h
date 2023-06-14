#pragma once
#include <iostream>
using namespace std;
typedef struct Point {
	int x;
	int y;

	bool operator==(const Point& other)
	{
		return (x == other.x) && (y == other.y);
	}

	Point& operator = (const Point& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}
} Point;
