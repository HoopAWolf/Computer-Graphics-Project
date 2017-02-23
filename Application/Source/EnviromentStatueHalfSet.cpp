#include "EnvironmentBase.h"

class Environmentstatuehalfset : public EnvironmentBase
{
public:

	Environmentstatuehalfset()
	{
		texture_string_ = "StatueBase_halfset";
		environmentID_ = 10;
		environment_symbol_ = 'L';

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