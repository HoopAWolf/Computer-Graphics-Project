#include "EnvironmentBase.h"

class EnvironmentChristmasTree : public EnvironmentBase
{
public:
	EnvironmentChristmasTree()
	{
		texture_string_ = "christmas_tree";
		environmentID_ = 1;
		environment_symbol_ = 'C';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'C';
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