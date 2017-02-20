#include "EnvironmentBase.h"

class EnvironmentThreeQuarterSet : public EnvironmentBase
{
public:
	 EnvironmentThreeQuarterSet()
	{
		texture_string_ = "statueBase_Three Quarter Set";
		environmentID_ = 14;
		environment_symbol_ = 'T';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'T';
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