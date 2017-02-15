#ifndef _MAP_BASE_H
#define _MAP_BASE_H_

#include <map>
#include "Vector3.h"

using std::map;

struct ArrayData
{
	char **mapArray_;
	Vector3 size_;
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

	void setMapSize(unsigned dimensionID, int x, int z);
	void generateMap(unsigned dimensionID);
	void setMapDataByCoord(unsigned dimensionID, char data, unsigned coordX, unsigned coordZ);

	ArrayData getMapData(unsigned dimensionID);
	char checkingMapDataByCoord(unsigned dimensionID, unsigned coordX, unsigned coordZ);


};

#endif