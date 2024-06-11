#include "../Library/gameutil.h"
#include <memory>
using namespace game_framework;
	class Ball_func{
	public:
		Ball_func();
		int Ball_func::ball_moving(int check_start, int brick_id_round[], CMovingBitmap brick_black[], int brick[], int check_overlap[],int heart[], int x_player, int y_player, CMovingBitmap Play) ;
		int Ball_func::boss_ball(int check_start,int heart[], int x_player, int y_player, CMovingBitmap Play, CMovingBitmap boss);
		int ball_x = 495;
		int ball_y = 640;
		int x_moving = 0;
		int y_moving = -15;
		CMovingBitmap Ball;
		
		
	protected:
		int background_left_max = 175;
		int background_right_max = 795;
		int background_under_max = 800;
		int background_top_max = 115;
	};
