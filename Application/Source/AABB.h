#ifndef _AABB_
#define _AABB_

#include "Vector3.h"

struct AABB
{
	AABB getBoundryAtCoord(Vector3 position)
	{
		AABB AABBatCoord;
		AABBatCoord.min = position + min;
		AABBatCoord.max = position + max;

		return AABBatCoord;
	}

	void setBoundry(Vector3 minInput, Vector3 maxInput)
	{
		min = minInput;
		max = maxInput;
	}

	Vector3 min, max;
};

#endif