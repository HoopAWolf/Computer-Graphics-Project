#ifndef _ENVIRONMENT_BASE_H_
#define _ENVIRONMENT_BASE_H_

#include <string>
#include "Vector3.h"

using std::string;


class EnvironmentBase
{

protected:
	string texture_string_;
	Vector3 position_;
	unsigned environmentID_;
	char environment_symbol_;
	Vector3 size_;

	char boundry_[40][40];

public:
	virtual ~EnvironmentBase(){}

	virtual Vector3 getPosition()
	{
		return position_;
	}

	virtual string getTextureString()
	{
		return texture_string_;
	}

	virtual unsigned getEnvironmentID()
	{
		return environmentID_;
	}

	virtual unsigned getEnvironmentSymbol()
	{
		return environment_symbol_;
	}

	virtual void setPosition(Vector3 coords)
	{
		position_ = coords;
	}

	char getBoundryChar(int coordX, int coordZ)
	{
		return boundry_[coordX][coordZ];
	}

	virtual void onInterection() = 0;
};

#endif