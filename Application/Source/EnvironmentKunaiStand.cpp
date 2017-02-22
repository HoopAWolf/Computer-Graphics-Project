#include "EnvironmentBase.h"

class EnvironmentKunaiStand : public EnvironmentBase
{
public:
	EnvironmentKunaiStand()
	{
		texture_string_ = "kunai_stand";
		environmentID_ = 6;
		environment_symbol_ = 'K';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'K';
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