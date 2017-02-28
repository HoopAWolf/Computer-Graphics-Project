#include "EnvironmentBase.h"

class EnvironmentFence : public EnvironmentBase
{
public:
	EnvironmentFence()
	{
		texture_string_ = "fence";
		environmentID_ = 2;
		environment_symbol_ = 'B';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'B';
		boundry_[1][2] = '#';

		boundry_[2][0] = '#';
		boundry_[2][1] = '#';
		boundry_[2][2] = '#';
		boundry_[2][3] = '#';
		boundry_[2][4] = '#';

		boundry_[3][2] = '#';

	}

	void onInterection(){}
};