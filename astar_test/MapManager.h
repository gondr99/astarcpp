#pragma once

#define MAP_LINE 10

class MapManager
{
public:
	static MapManager& GetInstance()
	{
		static MapManager s;
		return s;
	}
	
private:
	MapManager();
	MapManager(const MapManager& ref) : _mapData{ '0', }, _pathData{ '0', } {};
	MapManager& operator=(const MapManager& ref){};
	~MapManager();

private:
	char _mapData[MAP_LINE][21]; //������ null�� �� �ְ� ��ĭ
	char _pathData[MAP_LINE][21]; //��� ����
	
public:
	void ReadMapFile();
	void PrintMap();
	void ClearPath();
	void SetPath(int x, int y);
	bool CanMove(int x, int y);

	void SetColor(unsigned short text);
};

