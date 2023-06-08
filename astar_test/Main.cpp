#include <iostream>

#include "MapManager.h"
#include "PriorityQueue.h"
#include "Node.h"
using namespace std;

MapManager mapManager;
PriorityQueue heap;

int main()
{
	/*mapManager.ReadMapFile();
	mapManager.PrintMap();*/
	Node n1(0, 0, 0, 4.0);
	heap.Push(n1);
	Node n2(0, 1, 0, 2.0);
	heap.Push(n2);
	Node n3(1, 1, 0, 5.0);
	heap.Push(n3);
	Node n4(2, 2, 0, 7.0);
	heap.Push(n4);
	Node n5(2, 3, 0, 1.0);
	heap.Push(n5);

	heap.PrintHeap();

	Node p = heap.Pop();
	cout << "²¨³»¿Â ³ëµå : " << p.ToString() << endl;
	
	heap.PrintHeap();

	
	return 0;
}