#include "EnvironmentBase.h"

class EnvironmentOneQuarterSet : public EnvironmentBase
{
public:
	EnvironmentOneQuarterSet()
	{
		texture_string_ = "StatueBase_one quarter";
		environmentID_ = 12;
		environment_symbol_ = 'R';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'R';
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