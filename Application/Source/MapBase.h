#ifndef _MAP_BASE_H
#define _MAP_BASE_H_

#define MAXSIZEX 20
#define MAXSIZEZ 20

#include <map>

using std::map;

struct ArrayData
{
	int mapArray[MAXSIZEX][MAXSIZEZ];
};

class MapBase
{
private:
	map<unsigned, ArrayData> map_data_;
	static MapBase* s_instance;

public:
	static MapBase* instance()
	{
		if (!s_instance)
			s_instance = new MapBase;

		return s_instance;
	}

	void generateMap(unsigned dimensionID);
	void setMapDataByCoord(char data, unsigned coordX, unsigned coordZ);

	ArrayData getMapData(unsigned dimensionID);
	char checkingMapDataByCoord(unsigned coordX, unsigned coordZ);


};

#endif