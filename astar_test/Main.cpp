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
		cout << "경로를 못찾았습니다." << endl;
	}

	MapManager::GetInstance().PrintMap();
	
	return 0;
}