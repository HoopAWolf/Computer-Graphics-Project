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

	bool isAABBInsideAABB(AABB entity2) {
		return (min.x <= entity2.max.x && max.x >= entity2.min.x) &&
			(min.y <= entity2.max.y && max.y >= entity2.min.y) &&
			(min.z <= entity2.max.z && max.z >= entity2.min.z);
	}


	Vector3 min, max;
};

#endif