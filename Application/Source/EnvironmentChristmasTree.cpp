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
		boundry_[0][3] = '#';
		boundry_[0][4] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = '#';
		boundry_[1][2] = '#';
		boundry_[1][3] = '#';
		boundry_[1][4] = '#';

		boundry_[2][0] = '#';
		boundry_[2][1] = '#';
		boundry_[2][2] = 'C';
		boundry_[2][3] = '#';
		boundry_[2][4] = '#';

		boundry_[3][0] = '#';
		boundry_[3][1] = '#';
		boundry_[3][2] = '#';
		boundry_[3][3] = '#';
		boundry_[3][4] = '#';

		boundry_[4][0] = '#';
		boundry_[4][1] = '#';
		boundry_[4][2] = '#';
		boundry_[4][3] = '#';
		boundry_[4][4] = '#';
		

	}

	void onInterection(){}
};