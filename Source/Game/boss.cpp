#include "stdafx.h"
#include "boss.h"
#include <stdlib.h>

BOSS::BOSS() {
	
}
void BOSS::Boss_init() {
	Boss_background.LoadBitmap("Resources/background/boss_background.bmp");
	Boss_background.SetTopLeft(138, 85);
	Boss.LoadBitmap("Resources/boss/boss.bmp");
	Boss.SetTopLeft(370, 220);
	Boss2.LoadBitmap("Resources/boss/boss2.bmp");
	Boss2.SetTopLeft(370, 220);
	Boss_Die[0].LoadBitmap("Resources/boss/boss_dead1.bmp");
	Boss_Die[0].SetTopLeft(370, 220);
	Boss_Die[1].LoadBitmap("Resources/boss/boss_dead2.bmp");
	Boss_Die[1].SetTopLeft(370, 220);
	Boss_Die[2].LoadBitmap("Resources/boss/boss_dead3.bmp");
	Boss_Die[2].SetTopLeft(370, 220);
	Boss_Die[3].LoadBitmap("Resources/boss/boss_dead4.bmp");
	Boss_Die[3].SetTopLeft(370, 220);
	Boss_Die[4].LoadBitmap("Resources/boss/boss_dead5.bmp");
	Boss_Die[4].SetTopLeft(370, 220);
	Boss_Die[5].LoadBitmap("Resources/boss/boss_dead6.bmp");
	Boss_Die[5].SetTopLeft(370, 220);
	ENDING.LoadBitmap("Resources/END/END1.bmp");
	ENDING.SetTopLeft(0, 1000);
	ENDING2.LoadBitmap("Resources/END/boss_end.bmp");
	ENDING2.SetTopLeft(0, 90);
	ENDING3.LoadBitmap("Resources/END/boss_end2.bmp");
	ENDING3.SetTopLeft(0, 90);
	for (int i = 0; i < 5; i++) {
		attack[i].LoadBitmap("Resources/player/ball.bmp");
	}
	
}

void BOSS::Boss_start() {
	if (attack_time > 80) {
		Boss_background.ShowBitmap();
		Boss2.ShowBitmap();
		if (attack_time > 100) {
			if (attack_choose == 1) {
				Boss_attack1();
			}
			if (attack_choose == 2) {
				Boss_attack2();
			}
			if (attack_choose == 3) {
				Boss_attack3();
			}
		}
		if (attack_y[0] > 1000) {
			attack_time = 0;
			attack_choose = rand() % 3 + 1;
			for (int i = 0; i < 5; i++) {
				attack_DG[i] = 1;
				attack_x[i] = 495;
				attack_y[i] = 400;
			}
		}
		attack_time++;
	}
	else{
		Boss_background.ShowBitmap();
		Boss.ShowBitmap();
		attack_time++;
	}
}
void BOSS::Boss_show() {
	if (round_time > 80) {
		Boss_background.ShowBitmap();
		Boss.ShowBitmap();
		boss_heart = 30;
		attack_time = 0;
		for (int i = 0; i < 5; i++) {
			attack_DG[i] = 1;
			attack_x[i] = 495;
			attack_y[i] = 400;
		}
	}
	else {
		round_time++;
	}
}
void BOSS::Boss_overlab(CMovingBitmap ball, CMovingBitmap play,int heart[]) {
	if (CMovingBitmap::IsOverlap(Boss, ball) == true) {
		boss_heart -= 1;
	}
	for (int i = 0; i < 5; i++) {
		if (CMovingBitmap::IsOverlap(attack[i], play) == true && attack_DG[i] == 1) {
			attack_DG[i] = 0;
			heart[0] -= 1;
			break;
		}
	}
}

void BOSS::Boss_attack1() {
	attack[0].SetTopLeft(attack_x[0], attack_y[0]);
	attack[0].ShowBitmap();
	attack[1].SetTopLeft(attack_x[1], attack_y[1]);
	attack[1].ShowBitmap();
	attack[2].SetTopLeft(attack_x[2], attack_y[2]);
	attack[2].ShowBitmap();
	attack_y[0] += 10;
	attack_x[0] += 3;
	attack_y[1] += 10;
	attack_x[1] -= 3;
	attack_y[2] += 10;
}
void BOSS::Boss_attack2() {
	attack[0].SetTopLeft(attack_x[0], attack_y[0]);
	attack[0].ShowBitmap();
	attack[1].SetTopLeft(attack_x[1], attack_y[1]);
	attack[1].ShowBitmap();
	attack_y[0] += 10;
	attack_x[0] += 6;
	attack_y[1] += 10;
	attack_x[1] -= 6;
}
void BOSS::Boss_attack3() {
	attack[0].SetTopLeft(attack_x[0], attack_y[0]);
	attack[0].ShowBitmap();
	attack[1].SetTopLeft(attack_x[1], attack_y[1]);
	attack[1].ShowBitmap();
	attack[2].SetTopLeft(attack_x[2], attack_y[2]);
	attack[2].ShowBitmap();
	attack[3].SetTopLeft(attack_x[3], attack_y[3]);
	attack[3].ShowBitmap();
	attack[4].SetTopLeft(attack_x[4], attack_y[4]);
	attack[4].ShowBitmap();
	attack_y[0] += 10;
	attack_x[0] += 2;
	attack_y[1] += 10;
	attack_x[1] -= 2;
	attack_y[2] += 10;
	attack_x[2] += 0;
	attack_y[3] += 10;
	attack_x[3] += 4;
	attack_y[4] += 10;
	attack_x[4] -= 4;

}

void BOSS::Boss_dead() {
	if (dead_time < 240) {
		if (dead_time < 30) {
			Boss.ShowBitmap();
		}
		else if (dead_time >= 30 && dead_time < 60) {
			Boss_Die[0].ShowBitmap();
		}
		else if (dead_time >= 60 && dead_time < 90) {
			Boss_Die[1].ShowBitmap();
		}
		else if (dead_time >= 90 && dead_time < 120) {
			Boss_Die[2].ShowBitmap();
		}
		else if (dead_time >= 120 && dead_time < 150) {
			Boss_Die[3].ShowBitmap();
		}
		else if (dead_time >= 150 && dead_time < 180) {
			Boss_Die[4].ShowBitmap();
		}
		else if (dead_time >= 180 && dead_time < 240) {
			Boss_Die[5].ShowBitmap();
		}
		dead_time++;
	}
	else if (end_y == 90) {
		if (end_time >= 200) {
			ENDING3.ShowBitmap();
		}
		else if (end_time >= 100 && end_time < 200) {
			ENDING2.ShowBitmap();
			end_time++;
		}
		else {
			ENDING.ShowBitmap();
			end_time++;
		}
	}
	else {
		ENDING.ShowBitmap();
		ENDING.SetTopLeft(end_x, end_y);
		end_y -= 10;
	}
}

void BOSS::restart() {
	attack_choose = 1;
	attack_time = 0;
	round_time = 0;
	end_time = 0;
	dead_time = 0;
	end_x = 0;
	end_y = 1000;
	boss_heart = 30;
	ENDING.SetTopLeft(0, 1000);
	for (int i = 0; i < 5; i++) {
		attack_DG[i] = 1;
		attack_x[i] = 495;
		attack_y[i] = 400;
		attack[i].SetTopLeft(attack_x[i], attack_y[i]);
	}
}


