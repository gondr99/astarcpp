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

	//������ġ �־��ְ�
	openList->Push(Node(start.x, start.y, 0, CalcH(start) ) );
	
	bool result = false; //���� ã�Ҵ��� ����
	int cnt = 0; //�����ڵ�
	while (openList->Count() > 0)
	{
		Node* n = openList->Pop();
		//cout << n->ToString() << endl;
		FindOpenList(n); //n���� ���� ��� �˴� �˻�
		closeList.push_back(n); //�湮 ���� n�ֱ�

		if (*n->point == end)
		{
			result = true;
			break;
		}

		cnt++;
		if (cnt >= 10000)
		{
			cout << "����� ����" << endl;
			break;
		}
	}
	if (result)
	{
		routePath.clear();

		Node* last = closeList[closeList.size() - 1]; //������ ���� �����ͼ�

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
	//cout << currentNode->point->x << ", " << currentNode->point->y << " : Ž������" << endl;
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
				//cout << " : �̹� �湮" << endl;
				continue; //�̹� �湮�� ���ϱ� ����
			}

			if (MapManager::GetInstance().CanMove(p.x, p.y)) //�̵��� ������ ���̶�� 
			{
				float g = sqrt(pow(p.x - currentNode->point->x, 2) + pow(p.y - currentNode->point->y, 2)) + currentNode->G;

				Node newNode(p.x, p.y, g, g + CalcH(p));
				newNode.parent = currentNode;
				Node* find = openList->FindNode(newNode);
				//cout << "test: " << newNode.ToString() << endl;
				if (find != nullptr) //ã�Ҵٸ�
				{
					if (newNode.G < find->G) {
						find->G = newNode.G;
						find->F = newNode.F;
						find->parent = newNode.parent;
					}
					//cout << ": �̹� �־ ���� ��ü ";
				}
				else //�� ã�Ҵٸ�
				{
					openList->Push(newNode);
				}
			}
			else {
				//cout << " : �� �� ����";
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
