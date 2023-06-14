#include <iostream>
#include <fstream>
#include <string>
#include "MapManager.h"

using namespace std;

MapManager::MapManager()
{
	
}

MapManager::~MapManager()
{
}

void MapManager::ReadMapFile()
{
	ifstream fin("data/mapdata.txt");

	string buffer;
	
	int line = 0;
	while (fin.peek() != EOF)
	{
		getline(fin, buffer);
		//cout << buffer.length() << endl;
		buffer.copy(_mapData[line], buffer.length());
		line++;
	}

	fin.close();
}

void MapManager::PrintMap()
{
	for (int i = 0; i < MAP_LINE; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (_pathData[i][j] != '0') {
				cout << _pathData[i][j];
			}
			else {
				cout << _mapData[i][j];
			}
		}
		cout << endl;
	}
}

void MapManager::ClearPath()
{
	for (int i = 0; i < MAP_LINE; i++)
	{
		memset(_pathData[i], '0', sizeof(char) * 21);
	}
}

void MapManager::SetPath(int x, int y)
{
	_pathData[y][x] = '+';
}

bool MapManager::CanMove(int x, int y)
{
	if (x < 0 || y < 0 || x >= 21 || y >= MAP_LINE) {
		return false;
	}
	return _mapData[y][x] == '0'; //움직일 수 있는 곳이면 true
}


