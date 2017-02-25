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

	bool isPointInsideAABB(Vector3 position, Vector3 view) {
		Vector3 viewRange = position;

		/*std::cout << "/////////////////////////////////////////" << std::endl;
		std::cout << view << std::endl;
		std::cout << position << std::endl;*/

		Vector3 newView = (position - (position + view)).Normalized();

	/*	std::cout << newView << std::endl;
		std::cout << "/////////////////////////////////////////" << std::endl;*/
		for (int i = 0; i < 8; i++)
		{
			viewRange.x += ((newView.x < 0) ? -.5 : .5);
			viewRange.z += ((newView.z < 0) ? -.5 : .5);

			//std::cout << viewRange << std::endl;

			if ((viewRange.x >= min.x && viewRange.x <= max.x) &&
				(viewRange.y >= min.y && viewRange.y <= max.y) &&
				(viewRange.z >= min.z && viewRange.z <= max.z))
				return true;
		}

		return false;
	}


	Vector3 min, max;
};

#endif