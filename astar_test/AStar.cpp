#include <iostream>
#include <algorithm>
#include <cmath>
#include "Node.h"
#include "Common.h"
#include "AStar.h"
#include "PriorityQueue.h"
#include "MapManager.h"

using namespace std;

bool AStar::CalcRoute(Point start, Point end)
{
	destination = end;

	openList = new PriorityQueue();
	closeList.clear();

	//시작위치 넣어주고
	openList->Push(Node(start.x, start.y, 0, CalcH(start) ) );
	
	bool result = false; //길을 찾았는지 여부
	int cnt = 0; //안전코드
	while (openList->Count() > 0)
	{
		Node* n = openList->Pop();
		//cout << n->ToString() << endl;
		FindOpenList(n); //n에서 열린 노드 죄다 검색
		closeList.push_back(n); //방문 노드로 n넣기

		if (*n->point == end)
		{
			result = true;
			break;
		}

		cnt++;
		if (cnt >= 10000)
		{
			cout << "디버그 엔드" << endl;
			break;
		}
	}
	if (result)
	{
		routePath.clear();

		Node* last = closeList[closeList.size() - 1]; //마지막 원소 가져와서

		while (last->parent != nullptr)
		{
			routePath.push_back(*last->point);
			last = last->parent;
		}

		MapManager::GetInstance().ClearPath();
		for (auto it = routePath.begin(); it != routePath.end(); ++it)
		{
			//cout << "[ x = " << it->x << ", y = " << it->y << " ]" << endl;
			MapManager::GetInstance().SetPath(it->x, it->y);
		}
	}

	return result;
}

void AStar::FindOpenList(Node* currentNode)
{
	//cout << currentNode->point->x << ", " << currentNode->point->y << " : 탐색시작" << endl;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0) continue;
			Point p;
			p.x = currentNode->point->x + j;
			p.y = currentNode->point->y + i;

			auto it = find_if(closeList.begin(), closeList.end(), [&](Node* x)->bool {
				return *x->point == p;
			});
			//cout << p.x << ", " << p.y ;
			if (it != closeList.end()) {
				//cout << " : 이미 방문" << endl;
				continue; //이미 방문한 노드니까 없애
			}

			if (MapManager::GetInstance().CanMove(p.x, p.y)) //이동이 가능한 곳이라면 
			{
				float g = sqrt(pow(p.x - currentNode->point->x, 2) + pow(p.y - currentNode->point->y, 2)) + currentNode->G;

				Node newNode(p.x, p.y, g, g + CalcH(p));
				newNode.parent = currentNode;
				Node* find = openList->FindNode(newNode);
				//cout << "test: " << newNode.ToString() << endl;
				if (find != nullptr) //찾았다면
				{
					if (newNode.G < find->G) {
						find->G = newNode.G;
						find->F = newNode.F;
						find->parent = newNode.parent;
					}
					//cout << ": 이미 있어서 값만 교체 ";
				}
				else //못 찾았다면
				{
					openList->Push(newNode);
				}
			}
			else {
				//cout << " : 갈 수 없음";
			}
			//cout << endl;
		}
	}
}

float AStar::CalcH(Point pos)
{
	return sqrt(pow(destination.x - pos.x, 2) + pow(destination.y - pos.y, 2));
}

void AStar::PrintRoute()
{
}
