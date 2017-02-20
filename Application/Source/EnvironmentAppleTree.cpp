#include "EnvironmentBase.h"

class EnvironmentAppleTree : public EnvironmentBase
{
public:
	EnvironmentAppleTree()
	{
		texture_string_ = "apple_tree";
		environmentID_ = 0;
		environment_symbol_ = 'A';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'A';
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