#include "EnvironmentBase.h"

class EnvironmentHouse : public EnvironmentBase
{
public:
	EnvironmentHouse()
	{
		texture_string_ = "house";
		environmentID_ = 5;
		environment_symbol_ = 'H';

		boundry_[0][0] = '#';
		boundry_[0][1] = '#';
		boundry_[0][2] = '#';
		boundry_[0][3] = '#';
		boundry_[0][4] = '#';
		boundry_[0][5] = '#';
		boundry_[0][6] = '#';
		boundry_[0][7] = '#';
		boundry_[0][8] = '#';
		boundry_[0][9] = '#';
		boundry_[0][10] = '#';
		boundry_[0][11] = '#';
		boundry_[0][12] = '#';
		boundry_[0][13] = '#';
		boundry_[0][14] = '#';
		boundry_[0][15] = '#';
		boundry_[0][16] = '#';
		boundry_[0][17] = '#';
		boundry_[0][18] = '#';


		boundry_[1][0] = '#';
		boundry_[1][1] = '#';
		boundry_[1][2] = '#';
		boundry_[1][3] = '#';
		boundry_[1][4] = '#';
		boundry_[1][5] = '#';
		boundry_[1][6] = '#';
		boundry_[1][7] = '#';
		boundry_[1][8] = '#';
		boundry_[1][9] = '#';
		boundry_[1][10] = '#';
		boundry_[1][11] = '#';
		boundry_[1][12] = '#';
		boundry_[1][13] = '#';
		boundry_[1][14] = '#';
		boundry_[1][15] = '#';
		boundry_[1][16] = '#';
		boundry_[1][17] = '#';
		boundry_[1][18] = '#';


		boundry_[2][0] = '#';
		boundry_[2][1] = '#';
		boundry_[2][2] = '#';
		boundry_[2][3] = '#';
		boundry_[2][4] = '#';
		boundry_[2][5] = '#';
		boundry_[2][6] = '#';
		boundry_[2][7] = '#';
		boundry_[2][8] = '#';
		boundry_[2][9] = '#';
		boundry_[2][10] = '#';
		boundry_[2][11] = '#';
		boundry_[2][12] = '#';
		boundry_[2][13] = '#';
		boundry_[2][14] = '#';
		boundry_[2][15] = '#';
		boundry_[2][16] = '#';
		boundry_[2][17] = '#';
		boundry_[2][18] = '#';


		boundry_[3][0] = '#';
		boundry_[3][1] = '#';
		boundry_[3][2] = '#';
		boundry_[3][3] = '#';
		boundry_[3][4] = '#';
		boundry_[3][5] = '#';
		boundry_[3][6] = '#';
		boundry_[3][7] = '#';
		boundry_[3][8] = '#';
		boundry_[3][9] = '#';
		boundry_[3][10] = '#';
		boundry_[3][11] = '#';
		boundry_[3][12] = '#';
		boundry_[3][13] = '#';
		boundry_[3][14] = '#';
		boundry_[3][15] = '#';
		boundry_[3][16] = '#';
		boundry_[3][17] = '#';
		boundry_[3][18] = '#';


		boundry_[4][0] = '#';
		boundry_[4][1] = '#';
		boundry_[4][2] = '#';
		boundry_[4][3] = '#';
		boundry_[4][4] = '#';
		boundry_[4][5] = '#';
		boundry_[4][6] = '#';
		boundry_[4][7] = '#';
		boundry_[4][8] = '#';
		boundry_[4][9] = '#';
		boundry_[4][10] = '#';
		boundry_[4][11] = '#';
		boundry_[4][12] = '#';
		boundry_[4][13] = '#';
		boundry_[4][14] = '#';
		boundry_[4][15] = '#';
		boundry_[4][16] = '#';
		boundry_[4][17] = '#';
		boundry_[4][18] = '#';


		boundry_[5][0] = '#';
		boundry_[5][1] = '#';
		boundry_[5][2] = '#';
		boundry_[5][3] = '#';
		boundry_[5][4] = '#';
		boundry_[5][5] = '#';
		boundry_[5][6] = '#';
		boundry_[5][7] = '#';
		boundry_[5][8] = '#';
		boundry_[5][9] = '#';
		boundry_[5][10] = '#';
		boundry_[5][11] = '#';
		boundry_[5][12] = '#';
		boundry_[5][13] = '#';
		boundry_[5][14] = '#';
		boundry_[5][15] = '#';
		boundry_[5][16] = '#';
		boundry_[5][17] = '#';
		boundry_[5][18] = '#';


		boundry_[6][0] = '#';
		boundry_[6][1] = '#';
		boundry_[6][2] = '#';
		boundry_[6][3] = '#';
		boundry_[6][4] = '#';
		boundry_[6][5] = '#';
		boundry_[6][6] = '#';
		boundry_[6][7] = '#';
		boundry_[6][8] = '#';
		boundry_[6][9] = '#';
		boundry_[6][10] = '#';
		boundry_[6][11] = '#';
		boundry_[6][12] = '#';
		boundry_[6][13] = '#';
		boundry_[6][14] = '#';
		boundry_[6][15] = '#';
		boundry_[6][16] = '#';
		boundry_[6][17] = '#';
		boundry_[6][18] = '#';


		boundry_[7][0] = '#';
		boundry_[7][1] = '#';
		boundry_[7][2] = '#';
		boundry_[7][3] = '#';
		boundry_[7][4] = '#';
		boundry_[7][5] = '#';
		boundry_[7][6] = '#';
		boundry_[7][7] = '#';
		boundry_[7][8] = '#';
		boundry_[7][9] = '#';
		boundry_[7][10] = '#';
		boundry_[7][11] = '#';
		boundry_[7][12] = '#';
		boundry_[7][13] = '#';
		boundry_[7][14] = '#';
		boundry_[7][15] = '#';
		boundry_[7][16] = '#';
		boundry_[7][17] = '#';
		boundry_[7][18] = '#';

		boundry_[8][0] = '#';
		boundry_[8][1] = '#';
		boundry_[8][2] = '#';
		boundry_[8][3] = '#';
		boundry_[8][4] = '#';
		boundry_[8][5] = '#';
		boundry_[8][6] = '#';
		boundry_[8][7] = '#';
		boundry_[8][8] = '#';
		boundry_[8][9] = '#';
		boundry_[8][10] = '#';
		boundry_[8][11] = '#';
		boundry_[8][12] = '#';
		boundry_[8][13] = '#';
		boundry_[8][14] = '#';
		boundry_[8][15] = '#';
		boundry_[8][16] = '#';
		boundry_[8][17] = '#';
		boundry_[8][18] = '#';


		boundry_[9][0] = '#';
		boundry_[9][1] = '#';
		boundry_[9][2] = '#';
		boundry_[9][3] = '#';
		boundry_[9][4] = '#';
		boundry_[9][5] = '#';
		boundry_[9][6] = '#';
		boundry_[9][7] = '#';
		boundry_[9][8] = '#';
		boundry_[9][9] = '#';
		boundry_[9][10] = '#';
		boundry_[9][11] = '#';
		boundry_[9][12] = '#';
		boundry_[9][13] = '#';
		boundry_[9][14] = '#';
		boundry_[9][15] = '#';
		boundry_[9][16] = '#';
		boundry_[9][17] = '#';
		boundry_[9][18] = '#';


		boundry_[10][0] = '#';
		boundry_[10][1] = '#';
		boundry_[10][2] = '#';
		boundry_[10][3] = '#';
		boundry_[10][4] = '#';
		boundry_[10][5] = '#';
		boundry_[10][6] = '#';
		boundry_[10][7] = '#';
		boundry_[10][8] = '#';
		boundry_[10][9] = 'H';
		boundry_[10][10] = '#';
		boundry_[10][11] = '#';
		boundry_[10][12] = '#';
		boundry_[10][13] = '#';
		boundry_[10][14] = '#';
		boundry_[10][15] = '#';
		boundry_[10][16] = '#';
		boundry_[10][17] = '#';
		boundry_[10][18] = '#';


		boundry_[11][0] = '#';
		boundry_[11][1] = '#';
		boundry_[11][2] = '#';
		boundry_[11][3] = '#';
		boundry_[11][4] = '#';
		boundry_[11][5] = '#';
		boundry_[11][6] = '#';
		boundry_[11][7] = '#';
		boundry_[11][8] = '#';
		boundry_[11][9] = '#';
		boundry_[11][10] = '#';
		boundry_[11][11] = '#';
		boundry_[11][12] = '#';
		boundry_[11][13] = '#';
		boundry_[11][14] = '#';
		boundry_[11][15] = '#';
		boundry_[11][16] = '#';
		boundry_[11][17] = '#';
		boundry_[11][18] = '#';


		boundry_[12][0] = '#';
		boundry_[12][1] = '#';
		boundry_[12][2] = '#';
		boundry_[12][3] = '#';
		boundry_[12][4] = '#';
		boundry_[12][5] = '#';
		boundry_[12][6] = '#';
		boundry_[12][7] = '#';
		boundry_[12][8] = '#';
		boundry_[12][9] = '#';
		boundry_[12][10] = '#';
		boundry_[12][11] = '#';
		boundry_[12][12] = '#';
		boundry_[12][13] = '#';
		boundry_[12][14] = '#';
		boundry_[12][15] = '#';
		boundry_[12][16] = '#';
		boundry_[12][17] = '#';
		boundry_[12][18] = '#';


		boundry_[13][0] = '#';
		boundry_[13][1] = '#';
		boundry_[13][2] = '#';
		boundry_[13][3] = '#';
		boundry_[13][4] = '#';
		boundry_[13][5] = '#';
		boundry_[13][6] = '#';
		boundry_[13][7] = '#';
		boundry_[13][8] = '#';
		boundry_[13][9] = '#';
		boundry_[13][10] = '#';
		boundry_[13][11] = '#';
		boundry_[13][12] = '#';
		boundry_[13][13] = '#';
		boundry_[13][14] = '#';
		boundry_[13][15] = '#';
		boundry_[13][16] = '#';
		boundry_[13][17] = '#';
		boundry_[13][18] = '#';


		boundry_[14][0] = '#';
		boundry_[14][1] = '#';
		boundry_[14][2] = '#';
		boundry_[14][3] = '#';
		boundry_[14][4] = '#';
		boundry_[14][5] = '#';
		boundry_[14][6] = '#';
		boundry_[14][7] = '#';
		boundry_[14][8] = '#';
		boundry_[14][9] = '#';
		boundry_[14][10] = '#';
		boundry_[14][11] = '#';
		boundry_[14][12] = '#';
		boundry_[14][13] = '#';
		boundry_[14][14] = '#';
		boundry_[14][15] = '#';
		boundry_[14][16] = '#';
		boundry_[14][17] = '#';
		boundry_[14][18] = '#';


		boundry_[15][0] = '#';
		boundry_[15][1] = '#';
		boundry_[15][2] = '#';
		boundry_[15][3] = '#';
		boundry_[15][4] = '#';
		boundry_[15][5] = '#';
		boundry_[15][6] = '#';
		boundry_[15][7] = '#';
		boundry_[15][8] = '#';
		boundry_[15][9] = '#';
		boundry_[15][10] = '#';
		boundry_[15][11] = '#';
		boundry_[15][12] = '#';
		boundry_[15][13] = '#';
		boundry_[15][14] = '#';
		boundry_[15][15] = '#';
		boundry_[15][16] = '#';
		boundry_[15][17] = '#';
		boundry_[15][18] = '#';


		boundry_[16][0] = '#';
		boundry_[16][1] = '#';
		boundry_[16][2] = '#';
		boundry_[16][3] = '#';
		boundry_[16][4] = '#';
		boundry_[16][5] = '#';
		boundry_[16][6] = '#';
		boundry_[16][7] = '#';
		boundry_[16][8] = '#';
		boundry_[16][9] = '#';
		boundry_[16][10] = '#';
		boundry_[16][11] = '#';
		boundry_[16][12] = '#';
		boundry_[16][13] = '#';
		boundry_[16][14] = '#';
		boundry_[16][15] = '#';
		boundry_[16][16] = '#';
		boundry_[16][17] = '#';
		boundry_[16][18] = '#';


		boundry_[17][0] = '#';
		boundry_[17][1] = '#';
		boundry_[17][2] = '#';
		boundry_[17][3] = '#';
		boundry_[17][4] = '#';
		boundry_[17][5] = '#';
		boundry_[17][6] = '#';
		boundry_[17][7] = '#';
		boundry_[17][8] = '#';
		boundry_[17][9] = '#';
		boundry_[17][10] = '#';
		boundry_[17][11] = '#';
		boundry_[17][12] = '#';
		boundry_[17][13] = '#';
		boundry_[17][14] = '#';
		boundry_[17][15] = '#';
		boundry_[17][16] = '#';
		boundry_[17][17] = '#';
		boundry_[17][18] = '#';


		boundry_[18][0] = '#';
		boundry_[18][1] = '#';
		boundry_[18][2] = '#';
		boundry_[18][3] = '#';
		boundry_[18][4] = '#';
		boundry_[18][5] = '#';
		boundry_[18][6] = '#';
		boundry_[18][7] = '#';
		boundry_[18][8] = '#';
		boundry_[18][9] = '#';
		boundry_[18][10] = '#';
		boundry_[18][11] = '#';
		boundry_[18][12] = '#';
		boundry_[18][13] = '#';
		boundry_[18][14] = '#';
		boundry_[18][15] = '#';
		boundry_[18][16] = '#';
		boundry_[18][17] = '#';
		boundry_[18][18] = '#';

	}

	void onInterection(){}
};