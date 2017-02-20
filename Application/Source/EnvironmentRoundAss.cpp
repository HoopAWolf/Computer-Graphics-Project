#include "EnvironmentBase.h"

class EnvironmentRoundAss : public EnvironmentBase
{
public:
	EnvironmentRoundAss()
	{
		texture_string_ = "round_ass";
		environmentID_ = 16;
		environment_symbol_ = 'S';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'S';
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