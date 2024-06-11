#include "../Library/gameutil.h"
#include <vector>
#include <memory>
using namespace game_framework;
	class Player_func {
	public:
		Player_func();
		void player_show();
		int chara_move_right = 0;
		int chara_move_left = 0;
		int x_player = 450;
		int y_player = 700;
		int chara_time = 0;
		int heart[1] = {3};
		CMovingBitmap player;
		CMovingBitmap player_heart;
	protected:
		int background_left_max = 175;
		int background_right_max = 795;
		int background_under_max = 800;
		int background_top_max = 115;
	};