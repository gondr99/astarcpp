#include "Node.h"
#include "Common.h"

#include <iostream>
using namespace std;


Node::Node(int x, int y, float inG, float inF)
{
    point = new Point();
    point->x = x;
    point->y = y;
    G = inG;
    F = inF;
    parent = NULL;
}
Node::~Node()
{
    delete point;
}

int Node::Compare(Node& other)
{
    if (other.F == F)
        return 0;
    else
        return other.F < F ? -1 : 1;
}

string Node::ToString()
{
    return "[" + to_string(point->x) + ", " + to_string(point->y) + "," + to_string(F) + "]";
}
