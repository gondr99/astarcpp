#pragma once

#define MAP_LINE 10

class MapManager
{
private:
	char _mapData[MAP_LINE][21]; //������ null�� �� �ְ� ��ĭ

public:
	void ReadMapFile();
	void PrintMap();

	bool CanMove(int x, int y);
};

