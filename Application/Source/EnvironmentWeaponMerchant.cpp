#include "EnvironmentBase.h"

class EnvironmentWeaponMerchant : public EnvironmentBase
{
public:
	EnvironmentWeaponMerchant()
	{
		texture_string_ = "weapon_merchant";
		environmentID_ = 15;
		environment_symbol_ = 'W';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';

		boundry_[1][0] = '#';
		boundry_[1][1] = 'W';
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