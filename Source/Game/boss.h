#include "stdafx.h"
#include "../Library/gameutil.h"
using namespace game_framework;

class BOSS:public CMovingBitmap {
public:
	BOSS(void);
	void Boss_init();
	void Boss_attack1();
	void Boss_attack2();
	void Boss_attack3();
	void Boss_start();
	void Boss_dead();
	void Boss_show();
	void restart();
	void Boss_overlab(CMovingBitmap ball, CMovingBitmap play, int heart[]);
	int boss_heart = 30;
	CMovingBitmap Boss;
	CMovingBitmap Boss2;
private:
	int attack_DG[5] = {1,1,1,1,1};
	int attack_choose = 1;
	int attack_time = 0;
	int round_time = 0;
	int end_time = 0;
	int dead_time = 0;
	int end_x = 0;
	int end_y = 1000;
	int attack_x[5] = { 495 ,495 ,495 ,495 ,495};
	int attack_y[5] = { 400 ,400 ,400 ,400 ,400};

	CMovingBitmap attack[5];
	CMovingBitmap Boss_background;
	CMovingBitmap Boss_Die[6];
	CMovingBitmap ENDING;
	CMovingBitmap ENDING2;
	CMovingBitmap ENDING3;
	
};