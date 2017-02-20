#include "EnvironmentBase.h"

class EnvironmentstatueFullSet : public EnvironmentBase
{
public:
	EnvironmentstatueFullSet()
	{
		texture_string_ = "statueBase_FullSet";
		environmentID_ = 9;
		environment_symbol_ = 'U';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'U';
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