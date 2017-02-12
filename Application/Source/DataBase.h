#ifndef _DATA_BASE_H_
#define _DATA_BASE_H_

#include "ItemWeapon.h"
#include "ItemLightSword.cpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

class DataBase
{
private:
	static DataBase *s_instance;
	DataBase(){};

	vector<ItemWeapon *> weapon_base_;


public:
	static DataBase *instance()
	{
		if (!s_instance)
			s_instance = new DataBase;

		return s_instance;
	}

	void registerWeapons();
	ItemWeapon* getWeapon(int itemID);


};

#endif