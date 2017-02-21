#include "EnvironmentBase.h"

class EnvironmentTowerStructure : public EnvironmentBase
{
public:
	EnvironmentTowerStructure()
	{
		texture_string_ = "tower_structure";
		environmentID_ = 15;
		environment_symbol_ = 'X';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'J';
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