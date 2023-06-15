#include <iostream>

#include "MapManager.h"
#include "PriorityQueue.h"
#include "Node.h"
#include "AStar.h"
#include "Common.h"
using namespace std;

int main()
{
	MapManager::GetInstance().ReadMapFile();
	MapManager::GetInstance().ClearPath();
	//MapManager::GetInstance().PrintMap();
	
	AStar aStar;

	Point start = { 1, 1 };
	Point end = { 17, 8 };
	bool result = aStar.CalcRoute(start, end);
	if (!result)
	{
		cout << "��θ� ��ã�ҽ��ϴ�." << endl;
	}

	MapManager::GetInstance().PrintMap();
	
	return 0;
}