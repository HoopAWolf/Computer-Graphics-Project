#ifndef _ENTITY_BASE_H_
#define _ENTITY_BASE_H_

class EntityBase abstract
{
	virtual ~EntityBase() = 0;

private:
	enum ELEMENTAL_TYPE
	{
		LIGHTNING,
		FIRE,
		WATER,
		EARTH
	};

	ELEMENTAL_TYPE elemental_type_;

public:
	virtual ELEMENTAL_TYPE getElementalType() = 0;

};

#endif