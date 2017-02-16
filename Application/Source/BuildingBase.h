#ifndef _BUILDING_BASE_H_
#define _BUILDING_BASE_H_

#include <string>
#include "Vector3.h"

using std::string;


class BuildingBase
{

protected:
	string texture_string_;
	Vector3 position_;
	unsigned buildingID;
	Vector3 size_;

public:
	virtual ~BuildingBase(){}

	virtual Vector3 getPosition()
	{
		return position_;
	}

	virtual string getTextureString()
	{
		return texture_string_;
	}

	virtual unsigned gtBuildingID()
	{
		return buildingID;
	}

	virtual void setPosition(Vector3 coords)
	{
		position_ = coords;
	}

};

#endif