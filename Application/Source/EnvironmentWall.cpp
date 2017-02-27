#include "EnvironmentBase.h"

class EnvironmentWall : public EnvironmentBase
{
public:
	EnvironmentWall()
	{
		texture_string_ = "wall";
		environmentID_ = 0;
		environment_symbol_ = 'F';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'F';
		boundry_[1][2] = '#';

		boundry_[2][0] = '#';
		boundry_[2][1] = '#';
		boundry_[2][2] = '#';
		

		

	}

	void onInterection(){}
};