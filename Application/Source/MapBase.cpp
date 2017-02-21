#include "MapBase.h"
#include "DataBase.h"

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
	char currChar;
	int minPosX, minPosZ, maxPosX, maxPosZ;
	for (int x = 0; x < map_data_[dimensionID].size_.x; x++)
	{
		for (int z = 0; z < map_data_[dimensionID].size_.z; z++)
		{
			if (rand() % 100 < 5)
			{
				*(*(getMapData(dimensionID).mapArray_ + x) + z) = 'C';
				for (int i = 0; i < DataBase::instance()->sizeOfDataBase(1); i++)
				{
					if (DataBase::instance()->getEnvironmentBase(i)->getEnvironmentSymbol() == *(*(getMapData(dimensionID).mapArray_ + x) + z))
					{
						EnvironmentBase *tempObj = DataBase::instance()->getEnvironmentBase(i);
						tempObj->setPosition(Vector3(x, 0, z));

						DataBase::instance()->setEnvironment(dimensionID, tempObj);
					}
				}
			}
		}
	}

	//SETTING BOUNDRY BASED ON CUSTOM OBJ BOUNDRY IN CLASS
	for (int x = 0; x < getMapData(dimensionID).size_.x; x++)
	{
		for (int z = 0; z < getMapData(dimensionID).size_.z; z++)
		{
			if (checkingMapDataByCoord(dimensionID, x, z) != '#' && checkingMapDataByCoord(dimensionID, x, z) != 'O')
			{
				currChar = checkingMapDataByCoord(dimensionID, x, z);
				for (int i = 0; i < DataBase::instance()->sizeOfDataBase(1); i++)
				{
					if (DataBase::instance()->getEnvironmentBase(i)->getEnvironmentSymbol() == currChar)
					{
						for (int a = 0; a < 5; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (DataBase::instance()->getEnvironmentBase(i)->getBoundryChar(a, b) == currChar)
								{
									minPosX = -a;
									minPosZ = -b;
									goto here;
								}
							}
						}

					here:
						for (int a = 0; a < 5; a++)
						{
							if (x + minPosX > -1 && x + 5 < getMapData(dimensionID).size_.x)
							{
								for (int b = 0; b < 5; b++)
								{
									if (z + minPosZ > -1 && z + 5 < getMapData(dimensionID).size_.z)
									{
										if (checkingMapDataByCoord(dimensionID, (x + minPosX) + a, (z + minPosZ) + b) != currChar)
										{
											if (DataBase::instance()->getEnvironmentBase(i)->getBoundryChar(a, b) == '#')
											{
												setMapDataByCoord(dimensionID, DataBase::instance()->getEnvironmentBase(i)->getBoundryChar(a, b),
													(x + minPosX) + a,
													(z + minPosZ) + b);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//SETTING BOUNDRY FOR BORDERS
	for (int i = 0; i < getMapData(dimensionID).size_.x; i++)
	{
		for (int j = 0; j < getMapData(dimensionID).size_.z; j++)
		{
			if (i == 0 || i == getMapData(dimensionID).size_.x - 1)
				setMapDataByCoord(dimensionID, '#', i, j);
			else if (j == 0 || j == getMapData(dimensionID).size_.z - 1)
				setMapDataByCoord(dimensionID, '#', i, j);
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
	char currChar;
	int minPosX, minPosZ, maxPosX, maxPosZ;

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

				for (int i = 0; i < DataBase::instance()->sizeOfDataBase(1); i++)
				{
					if (DataBase::instance()->getEnvironmentBase(i)->getEnvironmentSymbol() == *(*(getMapData(dimensionID).mapArray_ + x) + z))
					{
						EnvironmentBase *tempObj;
						switch (i)
						{
						case 0:
							tempObj = new EnvironmentAppleTree;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 1:
							tempObj = new EnvironmentChristmasTree;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 2:
							tempObj = new EnvironmentFence;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 3:
							tempObj = new EnvironmentGiantSwordStand;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 4:
							tempObj = new EnvironmentHammerStand;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 5:
							tempObj = new EnvironmentHouse;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 6:
							tempObj = new EnvironmentKunaiStand;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 7:
							tempObj = new EnvironmentNicelookingTree;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 8:
							tempObj = new EnvironmentPortal;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 9:
							tempObj = new EnvironmentstatueFullSet;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 10:
							tempObj = new Environmentstatuehalfset;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 11:
							tempObj = new EnvironmentNoStatue;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 12:
							tempObj = new EnvironmentOneQuarterSet;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 13:
							tempObj = new EnvironmentTargetPractise;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 14:
							tempObj = new EnvironmentThreeQuarterSet;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 15:
							tempObj = new EnvironmentWeaponMerchant;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 16:
							tempObj = new EnvironmentRoundAss;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
						case 17:
							tempObj = new EnvironmentMinigunStan;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;
							//If Item spawninng goes wrong,Item Apple tree will spawn 
						default:
							tempObj = new EnvironmentAppleTree;
							tempObj->setPosition(Vector3(x, 0, z));

							DataBase::instance()->setEnvironment(dimensionID, tempObj);
							break;

						
						}
					}
				}
			}
			
			x++;
		}
	}

	myReadFile.close();

	//SETTING BOUNDRY BASED ON CUSTOM OBJ BOUNDRY IN CLASS
	for (int x = 0; x < getMapData(dimensionID).size_.x; x++)
	{
		for (int z = 0; z < getMapData(dimensionID).size_.z; z++)
		{
			if (checkingMapDataByCoord(dimensionID, x, z) != '#' && checkingMapDataByCoord(dimensionID, x, z) != 'O')
			{
				currChar = checkingMapDataByCoord(dimensionID, x, z);
				for (int i = 0; i < DataBase::instance()->sizeOfDataBase(1); i++)
				{
					if (DataBase::instance()->getEnvironmentBase(i)->getEnvironmentSymbol() == currChar)
					{
						for (int a = 0; a < 5; a++)
						{
							for (int b = 0; b < 5; b++)
							{
								if (DataBase::instance()->getEnvironmentBase(i)->getBoundryChar(a, b) == currChar)
								{
									minPosX = -a;
									minPosZ = -b;
									goto here;
								}
							}
						}

					here:
						for (int a = 0; a < 5; a++)
						{
							if (x + minPosX > -1 && x + 5 < getMapData(dimensionID).size_.x)
							{
								for (int b = 0; b < 5; b++)
								{
									if (z + minPosZ > -1 && z + 5 < getMapData(dimensionID).size_.z)
									{
										if (checkingMapDataByCoord(dimensionID, (x + minPosX) + a, (z + minPosZ) + b) != currChar)
										{
											if (DataBase::instance()->getEnvironmentBase(i)->getBoundryChar(a, b) == '#')
											{
												setMapDataByCoord(dimensionID, DataBase::instance()->getEnvironmentBase(i)->getBoundryChar(a, b),
													(x + minPosX) + a,
													(z + minPosZ) + b);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//SETTING BOUNDRY FOR BORDERS
	for (int i = 0; i < getMapData(dimensionID).size_.x; i++)
	{
		for (int j = 0; j < getMapData(dimensionID).size_.z; j++)
		{
			if (i == 0 || i == getMapData(dimensionID).size_.x - 1)
				setMapDataByCoord(dimensionID, '#', i, j);
			else if (j == 0 || j == getMapData(dimensionID).size_.z - 1)
				setMapDataByCoord(dimensionID, '#', i, j);
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
	if (coordX >= 0 && coordX < getMapData(dimensionID).size_.x && coordZ >= 0 && coordZ < getMapData(dimensionID).size_.z)
		return *(*(getMapData(dimensionID).mapArray_ + coordX) + coordZ);
	return '#';
}
