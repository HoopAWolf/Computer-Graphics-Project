#include "EnvironmentBase.h"

class EnvironmentRoundAss : public EnvironmentBase
{
public:
	EnvironmentRoundAss()
	{
		texture_string_ = "round_ass";
		environmentID_ = 16;
		environment_symbol_ = 'Q';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';
		boundry_[0][3] = '#';
		boundry_[0][4] = '#';
		boundry_[0][5] = '#';
		boundry_[0][6] = '#';
		

		boundry_[1][0] = '#';
		boundry_[1][1] = '#';
		boundry_[1][2] = '#';
		boundry_[1][3] = '#';
		boundry_[1][4] = '#';
		boundry_[1][5] = '#';
		boundry_[1][6] = '#';
		

		boundry_[2][0] = '#';
		boundry_[2][1] = '#';
		boundry_[2][2] = '#';
		boundry_[2][3] = '#';
		boundry_[2][4] = '#';
		boundry_[2][5] = '#';
		boundry_[2][6] = '#';
		

		boundry_[3][0] = '#';
		boundry_[3][1] = '#';
		boundry_[3][2] = '#';
		boundry_[3][3] = 'Q';
		boundry_[3][4] = '#';
		boundry_[3][5] = '#';
		boundry_[3][6] = '#';
		

		boundry_[4][0] = '#';
		boundry_[4][1] = '#';
		boundry_[4][2] = '#';
		boundry_[4][3] = '#';
		boundry_[4][4] = '#';
		boundry_[4][5] = '#';
		boundry_[4][6] = '#';
		

		boundry_[5][0] = '#';
		boundry_[5][1] = '#';
		boundry_[5][2] = '#';
		boundry_[5][3] = '#';
		boundry_[5][4] = '#';
		boundry_[5][5] = '#';
		boundry_[5][6] = '#';
		

		boundry_[6][0] = '#';
		boundry_[6][1] = '#';
		boundry_[6][2] = '#';
		boundry_[6][3] = '#';
		boundry_[6][4] = '#';
		boundry_[6][5] = '#';
		boundry_[6][6] = '#';
		


		
		

	}

	void onInterection(){}
};