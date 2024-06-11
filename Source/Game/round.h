#pragma
#include "../Library/gameutil.h"
#include "playmove.h"
#include "ballmove.h"
#include "round_init.h"

using namespace game_framework;

class Round_func {
public:
	Round_func(void);
	void brick_overlap();
	void start_run();
	void init_brick();
	void round_init(int choose_round);
	void round_to_init(std::string round);
	void round_check();
	void boss_check();
	void round_start();
	void boss_start(CMovingBitmap boss);
	void restart();
	void set_x_player(int x_player);
	void set_y_player(int y_player);
	void set_chara_move_right(int num);
	void set_chara_move_left(int num);
	int get_x_player();
	int get_y_player();
	void show_END();
	int get_background_max(std::string choose);
	void boss_init();
	int start_ck = 1;
	int check_start = 0;
	
	Player_func Play;
	Ball_func Ball;
	INIT_func Set_round;
	//關卡方塊
	int check_overlap[80] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int brick_id_round[80] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int brick[80] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	//控制條件
	int round_time = 0;
	int game_end = 0;
	int roundnumber = 1;
	
	
	
private:
	int background_left_max = 175;
	int background_right_max = 795;
	int background_under_max = 800;
	int background_top_max = 115;
	int start_x = 0;
	int start_y = 1000;
	int find_zero();
	CMovingBitmap background;
	CMovingBitmap brick_black[120];
	CMovingBitmap brick_green;
	CMovingBitmap background_round[31];
	CMovingBitmap ENDING;
	CMovingBitmap START;
};
