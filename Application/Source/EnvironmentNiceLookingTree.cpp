#include "EnvironmentBase.h"

class EnvironmentNicelookingTree : public EnvironmentBase
{
public:

	EnvironmentNicelookingTree()
	{
		texture_string_ = "nice_looking_tree";
		environmentID_ = 7;
		environment_symbol_ = 'N';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'N';
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