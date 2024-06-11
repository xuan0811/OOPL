#include "stdafx.h"
#include "playmove.h"

Player_func::Player_func() {

}
void Player_func::player_show() {
	if (chara_move_right == 1 && x_player < background_right_max - 80) {
		chara_move_left = 0;
		x_player += 5;
		chara_time++;
		if (chara_time == 8) {
			chara_time = 0;
			chara_move_right = 0;
		}
	}
	else {
		chara_move_right = 0;
	}
	if (chara_move_left == 1 && x_player > background_left_max) {
		chara_move_right = 0;
		x_player -= 5;
		chara_time++;
	if (chara_time == 8) {
		chara_time = 0;
		chara_move_left = 0;
		}
	}
	else {
		chara_move_left = 0;
	}
	for (int i = 0; i < heart[0]; i++) {
		player_heart.SetTopLeft(30, 800 - 20*i);
		player_heart.ShowBitmap();
	}
	player.SetTopLeft(x_player, y_player);
	player.ShowBitmap();
}


