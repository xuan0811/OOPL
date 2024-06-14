#include "stdafx.h"
#include "ballmove.h"

	Ball_func::Ball_func() {
		
	}

	int Ball_func::ball_moving(int check_start, int brick_id_round[], CMovingBitmap brick_black[], int brick[], int check_overlap[], int heart[], int x_player, int y_player, CMovingBitmap Play) {
		ball_x = ball_x + x_moving;
		ball_y = ball_y + y_moving;
		if (ball_y > 800) {
			check_start = 0;
			heart[0] = heart[0] - 1;
		}
		else {
			Ball.SetTopLeft(ball_x, ball_y);
			Ball.ShowBitmap();
		}
		if (ball_x >= background_right_max+10) {
			x_moving *= -1;
			ball_x = ball_x + x_moving;
		}
		else if (ball_x <= background_left_max-5) {
			x_moving *= -1;
			ball_x = ball_x + x_moving;
		}

		if (ball_y <= background_top_max) {
			y_moving *= -1;
			ball_y = ball_y + y_moving;
		}
		else if (ball_y > 800 || CMovingBitmap::IsOverlap(Play, Ball) == true) {
			if (ball_y < y_player - 10 && ball_x < x_player + 128 && ball_x >= x_player + 105) {
				x_moving = 9;
				y_moving = -6;
			}
			if (ball_y < y_player - 10 && ball_x < x_player + 105 && ball_x >= x_player + 81) {
				x_moving = 6;
				y_moving = -9;
			}
			if (ball_y < y_player - 10 && ball_x < x_player + 81 && ball_x >= x_player + 56) {
				x_moving = 3;
				y_moving = -12;
			}
			if (ball_y < y_player - 10 && ball_x < x_player + 56 && ball_x >= x_player + 34) {
				x_moving = 0;
				y_moving = -15;
			}
			if (ball_y < y_player - 10 && ball_x < x_player + 34 && ball_x >= x_player + 9) {
				x_moving = -3;
				y_moving = -12;
			}
			if (ball_y < y_player - 10 && ball_x < x_player + 9 && ball_x >= x_player - 15) {
				x_moving = -6;
				y_moving = -9;
			}
			if (ball_y < y_player - 10 && ball_x < x_player - 15 && ball_x >= x_player - 38) {
				x_moving = -9;
				y_moving = -6;
			}
		}
		for (int i = 79; i >= 0; i--) {
			if (CMovingBitmap::IsOverlap(Ball, brick_black[brick_id_round[i]]) == true &&  check_overlap[i] == 1) {
				brick[i] -= 1;
				if(brick[i] ==0)check_overlap[i] = 0;
				if (ball_y < brick_black[brick_id_round[i]].GetTop() - 12 && y_moving > 0 || ball_y > brick_black[brick_id_round[i]].GetTop() + 13 && y_moving < 0) {
					y_moving *= -1;
					ball_y = ball_y + y_moving;
				}
				if (ball_x >= brick_black[brick_id_round[i]].GetLeft() - 17 && ball_x <= brick_black[brick_id_round[i]].GetLeft() + 55 && ball_y > brick_black[brick_id_round[i]].GetTop() - 12 && ball_y < brick_black[brick_id_round[i]].GetTop() + 13) {
					x_moving *= -1;
					ball_x = ball_x + x_moving;
				}
				break;
			}
		}
		return check_start ;
	}

	int Ball_func::boss_ball(int check_start,int heart[],int x_player, int y_player, CMovingBitmap Play, CMovingBitmap boss) {
		ball_x = ball_x + x_moving;
		ball_y = ball_y + y_moving;
		if (ball_y > 800) {
			check_start = 0;
			heart[0] -= 1;
		}
		else {
			Ball.SetTopLeft(ball_x, ball_y);
			Ball.ShowBitmap();
		}
		if (ball_x >= background_right_max + 18) {
			x_moving *= -1;
			ball_x = ball_x + x_moving;
		}
		else if (ball_x <= background_left_max +2) {
			x_moving *= -1;
			ball_x = ball_x + x_moving;
		}

		if (ball_y <= background_top_max) {
			y_moving *= -1;
			ball_y = ball_y + y_moving;
		}
		else if (ball_y > 800 || CMovingBitmap::IsOverlap(Play, Ball) == true) {
			if (ball_y < y_player - 10 && ball_x < x_player + 128 && ball_x >= x_player + 105) {
				x_moving = 9;
				y_moving = -6;
			}
			if (ball_y < y_player - 10 && ball_x < x_player + 105 && ball_x >= x_player + 81) {
				x_moving = 6;
				y_moving = -9;
			}
			if (ball_y < y_player - 10 && ball_x < x_player + 81 && ball_x >= x_player + 56) {
				x_moving = 3;
				y_moving = -12;
			}
			if (ball_y < y_player - 10 && ball_x < x_player + 56 && ball_x >= x_player + 34) {
				x_moving = 0;
				y_moving = -15;
			}
			if (ball_y < y_player - 10 && ball_x < x_player + 34 && ball_x >= x_player + 9) {
				x_moving = -3;
				y_moving = -12;
			}
			if (ball_y < y_player - 10 && ball_x < x_player + 9 && ball_x >= x_player - 15) {
				x_moving = -6;
				y_moving = -9;
			}
			if (ball_y < y_player - 10 && ball_x < x_player - 15 && ball_x >= x_player - 38) {
				x_moving = -9;
				y_moving = -6;
			}
		}
		else if (CMovingBitmap::IsOverlap(boss, Ball) == true) {
			if (ball_y > 534 && y_moving < 0 || ball_y < 206 && y_moving > 0) {
				y_moving *= -1;
				ball_y = ball_y + y_moving;
			}
			if (ball_x >= 345 && ball_x <= 640 && ball_y <= 534 && ball_y >= 206) {
				x_moving *= -1;
				ball_x = ball_x + x_moving;
			}
		}
		return check_start;
	}
