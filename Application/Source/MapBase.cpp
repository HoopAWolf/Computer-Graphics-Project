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
			if (rand() % 100 < 5)
				*(*(getMapData(dimensionID).mapArray_ + x) + z) = 'C';
		}
	}

	for (int x = 0; x < getMapData(dimensionID).size_.x; x++)
	{
		for (int z = 0; z < getMapData(dimensionID).size_.z; z++)
		{
			if (checkingMapDataByCoord(dimensionID, x, z) == 'C')
			{
				for (int a = x - 1; a < x + 2; a++)
				{
					if (a > -1 && a < getMapData(dimensionID).size_.x)
					{
						for (int b = z - 1; b < z + 2; b++)
						{
							if (b > -1 && b < getMapData(dimensionID).size_.z)
							{
								if (checkingMapDataByCoord(dimensionID, a, b) != '#' && checkingMapDataByCoord(dimensionID, a, b) != 'C')
									setMapDataByCoord(dimensionID, '#', a, b);
							}
						}
					}
				}
			}
		}
	}

	/*for (int x = 0; x < getMapData(dimensionID).size_.x; x++)
	{
		for (int z = 0; z < getMapData(dimensionID).size_.z; z++)
		{
			std::cout << checkingMapDataByCoord(dimensionID, x, z);
		}
		std::cout << std::endl;
	}*/
}

void MapBase::generateMap(unsigned dimensionID, const std::string fileName)
{
	std::ifstream myReadFile;
	string lineInfo;

	myReadFile.open("Map//" + fileName);

	if (!myReadFile.is_open()) {  //CHECKING IF THERE IS SUCH FILE NAME
		std::cout << "Impossible to open " << fileName << ". Are you in the right directory ?\n";
	}
	else if (myReadFile.is_open()) {
		unsigned x = 0;

		while (!myReadFile.eof()) {

			std::getline(myReadFile, lineInfo);

			for (int z = 0; z < lineInfo.size(); z++)
			{
				*(*(getMapData(dimensionID).mapArray_ + x) + z) = lineInfo[z];
			}
			
			x++;
		}
	}

	myReadFile.close();

	for (int x = 0; x < getMapData(dimensionID).size_.x; x++)
	{
		for (int z = 0; z < getMapData(dimensionID).size_.z; z++)
		{
			if (checkingMapDataByCoord(dimensionID, x, z) == 'C')
			{
				for (int a = x - 1; a < x + 2; a++)
				{
					if (a > -1 && a < getMapData(dimensionID).size_.x)
					{
						for (int b = z - 1; b < z + 2; b++)
						{
							if (b > -1 && b < getMapData(dimensionID).size_.z)
							{
								if (checkingMapDataByCoord(dimensionID, a, b) != '#' && checkingMapDataByCoord(dimensionID, a, b) != 'C')
									setMapDataByCoord(dimensionID, '#', a, b);
							}
						}
					}
				}
			}
		}
	}

	/*for (int x = 0; x < getMapData(dimensionID).size_.x; x++)
	{
		for (int z = 0; z < getMapData(dimensionID).size_.z; z++)
		{
			std::cout << checkingMapDataByCoord(dimensionID, x, z);
		}
		std::cout << std::endl;
	}*/
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
