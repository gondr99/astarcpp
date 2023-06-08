#pragma once

#define MAP_LINE 10

class MapManager
{
private:
	char _mapData[MAP_LINE][21]; //마지막 null들어갈 수 있게 한칸

public:
	void ReadMapFile();
	void PrintMap();

	bool CanMove(int x, int y);
};

