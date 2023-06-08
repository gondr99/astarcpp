#include <iostream>
#include <fstream>
#include <string>
#include "MapManager.h"

using namespace std;

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
		cout << _mapData[i] << endl;
	}
}

bool MapManager::CanMove(int x, int y)
{
	return _mapData[y][x] == '0'; //움직일 수 있는 곳이면 true
}


