#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "MapManager.h"

using namespace std;

enum class ColorSet
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

void MapManager::SetColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

MapManager::MapManager() : _mapData {'0',}, _pathData{'0',}
{
	system("mode con:cols=100 lines=50");
	
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
	cout << line << endl;
	fin.close();
}

void MapManager::PrintMap()
{
	for (int i = 0; i < MAP_LINE; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (_pathData[i][j] != '0') {
				SetColor( static_cast<int>( ColorSet::BLUE));
				cout << _pathData[i][j];
			}
			else if(_mapData[i][j] == '*') {
				SetColor(static_cast<int>(ColorSet::DARK_GRAY));
				cout << _mapData[i][j];
			}
			else {
				SetColor(static_cast<int>(ColorSet::WHITE));
				cout << _mapData[i][j];
			}
		}
		cout << "---" << i << endl;
	}
	SetColor(static_cast<int>(ColorSet::WHITE));
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


