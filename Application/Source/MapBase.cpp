#include "MapBase.h"

void MapBase::setMapSize(unsigned dimensionID, int x, int z)
{
	ArrayData tempData;
	
	tempData.mapArray_ = new char*[x];

	for (int i = 0; i < x; i++)
		tempData.mapArray_[i] = new char[z];

	tempData.size_ = Vector3(x, 0, z);

	map_data_[dimensionID] = tempData;
}

void MapBase::generateMap(unsigned dimensionID)
{
	for (int x = 0; x < map_data_[dimensionID].size_.x; x++)
	{
		for (int z = 0; z < map_data_[dimensionID].size_.z; z++)
		{
			*(*(getMapData(dimensionID).mapArray_ + x) + z) = 'C';
		}
	}
}

void MapBase::setMapDataByCoord(unsigned dimensionID, char data, unsigned coordX, unsigned coordZ)
{
	*(*(getMapData(dimensionID).mapArray_ + coordX) + coordZ) = data;
}

ArrayData MapBase::getMapData(unsigned dimensionID)
{
	return map_data_[dimensionID];
}

char MapBase::checkingMapDataByCoord(unsigned dimensionID, unsigned coordX, unsigned coordZ)
{
	return *(*(getMapData(dimensionID).mapArray_ + coordX) + coordZ);
}
