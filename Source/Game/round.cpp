#include "stdafx.h"
#include "../Library/gameutil.h"
#include "round.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

	Round_func::Round_func() {

	}
	void Round_func::round_to_init(std::string round) {
		Set_round.round_to_init(round, brick_id_round, brick, check_overlap,brick_black);
	}
	void Round_func::round_init(int choose_round) {
		if (round_time < 80) {
			background_round[choose_round].ShowBitmap();
			round_time++;
		}
		else {
			background.ShowBitmap();
			Play.player_show();
			Ball.ball_x = Play.x_player + 55;
			Ball.ball_y = Play.y_player - 20;
			Ball.Ball.SetTopLeft(Ball.ball_x, Ball.ball_y);
			Ball.Ball.ShowBitmap();
			brick_overlap();
			Ball.x_moving = 0;
			Ball.y_moving = -15;
		}
	}
	void Round_func::boss_init() {
		if (round_time < 80) {
			background_round[0].ShowBitmap();
			Play.heart[0] = 5;
			round_time++;
		}
		else {
			Play.player_show();
			Ball.ball_x = Play.x_player + 55;
			Ball.ball_y = Play.y_player - 20;
			Ball.Ball.SetTopLeft(Ball.ball_x, Ball.ball_y);
			Ball.Ball.ShowBitmap();
			Ball.x_moving = 3;
			Ball.y_moving = -15;
		}
	
	}
	void Round_func::brick_overlap() {
		for (int i = 0; i < 80; i++) {
			if (brick[i]>0) {
				brick_black[brick_id_round[i]].ShowBitmap();
			}
		}
	}
	void Round_func::start_run() {
		if (start_y == 90) {
			if (round_time > 120) {
				start_ck = 0;
				round_time = 0;
			}
			else {
				START.ShowBitmap();
				round_time++;
			}
		}
		else {
			start_y -= 10;
			START.SetTopLeft(start_x, start_y);
			START.ShowBitmap();
		}
	}
	void Round_func::init_brick() {
		background.LoadBitmap("Resources/background/background.bmp");
		background.SetTopLeft(120, 90);
		ENDING.LoadBitmap("Resources/END/ending.bmp");
		ENDING.SetTopLeft(60, 110);
		START.LoadBitmap("Resources/menu/start.bmp");
		START.SetTopLeft(0, 1000);
		Ball.Ball.LoadBitmap("Resources/player/ball.bmp",RGB(255,255,255));
		Ball.Ball.SetTopLeft(450, 700);
		Play.player.LoadBitmap("Resources/player/player.bmp");
		Play.player_heart.LoadBitmap("Resources/player/player_heart.bmp");
		for (int i = 0; i < 120; i++) {
			if (i>=0&&i<15) {
				brick_black[i].LoadBitmap("Resources/brick/brick_green.bmp");
			}
			else if (i >= 15 && i < 30) {
				brick_black[i].LoadBitmap("Resources/brick/blue.bmp");
			}
			else if (i >= 30 && i < 45) {
				brick_black[i].LoadBitmap("Resources/brick/blue2.bmp");
			}
			else if (i >= 45 && i < 60) {
				brick_black[i].LoadBitmap("Resources/brick/orange.bmp");
			}
			else if (i >= 60 && i < 75) {
				brick_black[i].LoadBitmap("Resources/brick/orange2.bmp");
			}
			else if (i >= 75 && i < 90) {
				brick_black[i].LoadBitmap("Resources/brick/iron.bmp");
			}
			else if (i >= 90 && i < 105) {
				brick_black[i].LoadBitmap("Resources/brick/pink.bmp");
			}
			else if (i >= 105 && i < 120) {
				brick_black[i].LoadBitmap("Resources/brick/gold.bmp");
			}
			
		}
		background_round[1].LoadBitmap("Resources/round/round1.bmp");
		background_round[1].SetTopLeft(0, 90);
		background_round[2].LoadBitmap("Resources/round/round2.bmp");
		background_round[2].SetTopLeft(0, 90);
		background_round[3].LoadBitmap("Resources/round/round3.bmp");
		background_round[3].SetTopLeft(0, 90);
		background_round[4].LoadBitmap("Resources/round/round4.bmp");
		background_round[4].SetTopLeft(0, 90);
		background_round[5].LoadBitmap("Resources/round/round5.bmp");
		background_round[5].SetTopLeft(0, 90);
		background_round[6].LoadBitmap("Resources/round/round6.bmp");
		background_round[6].SetTopLeft(0, 90);
		background_round[7].LoadBitmap("Resources/round/round7.bmp");
		background_round[7].SetTopLeft(0, 90);
		background_round[8].LoadBitmap("Resources/round/round8.bmp");
		background_round[8].SetTopLeft(0, 90);
		background_round[9].LoadBitmap("Resources/round/round9.bmp");
		background_round[9].SetTopLeft(0, 90);
		background_round[10].LoadBitmap("Resources/round/round10.bmp");
		background_round[10].SetTopLeft(0, 90);
		background_round[11].LoadBitmap("Resources/round/round11.bmp");
		background_round[11].SetTopLeft(0, 90);
		background_round[12].LoadBitmap("Resources/round/round12.bmp");
		background_round[12].SetTopLeft(0, 90);
		background_round[13].LoadBitmap("Resources/round/round13.bmp");
		background_round[13].SetTopLeft(0, 90);
		background_round[14].LoadBitmap("Resources/round/round14.bmp");
		background_round[14].SetTopLeft(0, 90);
		background_round[15].LoadBitmap("Resources/round/round15.bmp");
		background_round[15].SetTopLeft(0, 90);
		background_round[16].LoadBitmap("Resources/round/round16.bmp");
		background_round[16].SetTopLeft(0, 90);
		background_round[17].LoadBitmap("Resources/round/round17.bmp");
		background_round[17].SetTopLeft(0, 90);
		background_round[18].LoadBitmap("Resources/round/round18.bmp");
		background_round[18].SetTopLeft(0, 90);
		background_round[19].LoadBitmap("Resources/round/round19.bmp");
		background_round[19].SetTopLeft(0, 90);
		background_round[20].LoadBitmap("Resources/round/round20.bmp");
		background_round[20].SetTopLeft(0, 90);
		background_round[21].LoadBitmap("Resources/round/round21.bmp");
		background_round[21].SetTopLeft(0, 90);
		background_round[22].LoadBitmap("Resources/round/round22.bmp");
		background_round[22].SetTopLeft(0, 90);
		background_round[23].LoadBitmap("Resources/round/round23.bmp");
		background_round[23].SetTopLeft(0, 90);
		background_round[24].LoadBitmap("Resources/round/round24.bmp");
		background_round[24].SetTopLeft(0, 90);
		background_round[25].LoadBitmap("Resources/round/round25.bmp");
		background_round[25].SetTopLeft(0, 90);
		background_round[26].LoadBitmap("Resources/round/round26.bmp");
		background_round[26].SetTopLeft(0, 90);
		background_round[27].LoadBitmap("Resources/round/round27.bmp");
		background_round[27].SetTopLeft(0, 90);
		background_round[28].LoadBitmap("Resources/round/round28.bmp");
		background_round[28].SetTopLeft(0, 90);
		background_round[29].LoadBitmap("Resources/round/round29.bmp");
		background_round[29].SetTopLeft(0, 90);
		background_round[30].LoadBitmap("Resources/round/round30.bmp");
		background_round[30].SetTopLeft(0, 90);
		background_round[0].LoadBitmap("Resources/round/round31.bmp");
		background_round[0].SetTopLeft(0, 90);
	}

	int Round_func::find_zero() {
		for (int i = 0; i < 80; i++) {
			if (brick[i] > 0)return 1;
		}
		return 0;
	}

	void Round_func::round_check() {
		if (find_zero() && Play.heart[0] > 0) {
		}
		else if (Play.heart[0] == 0) {
			game_end = 1;
		}
		else {
			roundnumber += 1;
			Set_round.brick_init = 1;
			check_start = 0;
			round_time = 0;
			Play.heart[0] = 3;
		}
	}
	void Round_func::boss_check() {
		if (Play.heart[0] > 0) {
		}
		else if (Play.heart[0] == 0) {
			game_end = 1;
		}
		else {
			roundnumber += 1;
			Set_round.brick_init = 1;
			check_start = 0;
			round_time = 0;
			Play.heart[0] = 3;
		}
	}
	void Round_func::round_start() {
		background.ShowBitmap();
		check_start = Ball.ball_moving(check_start, brick_id_round, brick_black,brick,check_overlap,Play.heart,Play.x_player, Play.y_player, Play.player);
		Play.player_show();
		brick_overlap();
		round_check();
	}
	void Round_func::boss_start(CMovingBitmap boss) {
		check_start = Ball.boss_ball(check_start,Play.heart,Play.x_player, Play.y_player, Play.player,boss);
		Play.player_show();
		boss_check();
	}
	int Round_func::get_x_player() {
		return Play.x_player;
	}
	int Round_func::get_y_player() {
		return Play.y_player;
	}
	void Round_func::set_x_player(int x_player) {
		Play.x_player = x_player;
	}
	void Round_func::set_y_player(int y_player) {
		Play.y_player = y_player;

	}
	void Round_func::show_END() {
		ENDING.ShowBitmap();
	}
	void Round_func::set_chara_move_right(int num) {
		Play.chara_move_right = num;
	}
	void Round_func::set_chara_move_left(int num) {
		Play.chara_move_left = num;
	}

	int Round_func::get_background_max(std::string choose) {
		if (choose == "left") {
			return  this-> background_left_max;
		}
		else if (choose == "right") {
			return this-> background_right_max;
		}
		else if (choose == "top") {
			return this-> background_top_max;
		}
		else if (choose == "under") {
			return this-> background_under_max;
		}
		return this-> background_left_max;
	}

	void Round_func::restart() {
		roundnumber = 1;
		check_start = 0;
		round_time = 0;
		Set_round.brick_init = 1;
		game_end = 0;
		start_ck = 1;
		start_x = 0;
		start_y = 1000;
		START.SetTopLeft(0, 1000);
		Play.heart[0] = 3;
		for (int i = 0; i < 80; i++) {
			check_overlap[i] = 0;
			brick[i] = 0;
		}
	}