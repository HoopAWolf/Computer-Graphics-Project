#include "EnvironmentBase.h"

class EnvironmentGiantSwordStand : public EnvironmentBase
{
public:
	EnvironmentGiantSwordStand()
	{
		texture_string_ = "giant_sword_stand";
		environmentID_ = 3;
		environment_symbol_ = 'G';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'G';
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