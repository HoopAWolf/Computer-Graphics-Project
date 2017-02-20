#include "EnvironmentBase.h"

class EnvironmentTargetPractise : public EnvironmentBase
{
public:
	EnvironmentTargetPractise()
	{
		texture_string_ = "targetPractise";
		environmentID_ = 13;
		environment_symbol_ = 'I';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'I';
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