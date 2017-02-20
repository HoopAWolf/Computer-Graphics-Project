#include "EnvironmentBase.h"

class EnvironmentHammerStand : public EnvironmentBase
{
public:
	EnvironmentHammerStand()
	{
		texture_string_ = "hammer_stand";
		environmentID_ = 4;
		environment_symbol_ = 'M';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'M';
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