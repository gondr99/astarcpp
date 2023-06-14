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
    parent = nullptr;
    
}
Node::~Node()
{
    delete point;
}

Node::Node(const Node& other)
{
    //cout << "복사 생성자" << endl;
    this->point = new Point();
    this->point->x = other.point->x;
    this->point->y = other.point->y;

    this->F = other.F;
    this->G = other.G;
    this->parent = other.parent;
}

Node& Node::operator=(const Node& other)
{
    //cout << "복사 대입" << endl;
    if (this != &other) {
        if(this->point != nullptr)
            delete this->point;
        this->point = new Point();
        this->point->x = other.point->x;
        this->point->y = other.point->y;

        this->F = other.F;
        this->G = other.G;
        this->parent = parent;
    }
    return *this;
}

int Node::Compare(Node* other)
{
    if (other->F == F)
        return 0;
    else
        return other->F < F ? -1 : 1;
}

string Node::ToString()
{
    return "[" + to_string(point->x) + ", " + to_string(point->y) + "," + to_string(F) + "]" + (parent == nullptr ? "부모 null" : "부모 : " + to_string(parent->F) );
}
