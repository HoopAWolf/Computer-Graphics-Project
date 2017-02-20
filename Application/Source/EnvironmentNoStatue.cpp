#include "EnvironmentBase.h"

class EnvironmentNoStatue : public EnvironmentBase
{
public:
	EnvironmentNoStatue()
	{
		texture_string_ = "StatueBase_noStatue";
		environmentID_ = 11;
		environment_symbol_ = 'E';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'E';
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