#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	round.init_brick();
	boss.Boss_init();
	Menu1.LoadBitmap("Resources/menu/load_start1.bmp");
	Menu2.LoadBitmap("Resources/menu/load_start2.bmp");
	Menu1.SetTopLeft(0, 90);
	Menu2.SetTopLeft(0, 90);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_RIGHT && round.Play.x_player <= round.get_background_max("right") - 55) {
		round.Play.chara_move_right = 1;
	}
	if (nChar == VK_LEFT && round.Play.x_player >= round.get_background_max("left")) {
		round.Play.chara_move_left = 1;
	}
	if (nChar == VK_UP) {
		round.check_start = 1;
	}
	if (nChar == VK_F1) {
		round.roundnumber++;
		round.check_start = 0;
		round.round_time = 0;
		round.Set_round.brick_init = 1;
		for (int i = 0; i < 80; i++) {
			round.check_overlap[i] = 0;
			round.brick[i] = 0;
		}
	}
	if (nChar == VK_F5) {
		start = 1;
		round.game_end = 0;
		restrat_time = 0;
	}
	if (nChar == VK_F3) {
		round.roundnumber = roundnumber;
		start = 0;
		restrat_time = 0;
	}
	if (nChar == VK_RETURN) {
		start = 0;
		restrat_time = 0;
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	round.check_start = 1;
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	if (round.roundnumber == 31) {
		if (point.x <= round.get_background_max("right") - 39 && point.x >= round.get_background_max("left") + 54)
			round.Play.x_player = point.x - 55;
	}
	else if (point.x <= round.get_background_max("right") - 30 && point.x >= round.get_background_max("left") + 60)
		round.Play.x_player = point.x - 55;
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	round.check_start = 1;
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	if (round.game_end) {
		if (restrat_time == 300) {
			start = 1;
			round.game_end = 0;
			Menu = 0;
		}
		round.show_END();
		restrat_time++;
	}
	else if (start) {
		if (Menu <= 40) {
			Menu1.ShowBitmap();
		}
		else if (Menu > 40 && Menu <= 80) {
			Menu2.ShowBitmap();
		}
		else {
			Menu1.ShowBitmap();
			Menu = 0;
		}
		round.restart();
		boss.restart();
		Menu++;

	}
	else if (round.roundnumber == 1) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.start_ck) {
				round.start_run();
			}
			else {
				if (round.Set_round.brick_init)round.round_to_init("map/round1.txt");
				round.round_init(1);
			}
		}
	}
	else if (round.roundnumber == 2) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round2.txt");
			round.round_init(2);
		}
	}
	else if (round.roundnumber == 3) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round3.txt");
			round.round_init(3);
		}
	}
	else if (round.roundnumber == 4) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round4.txt");
			round.round_init(4);
		}
	}
	else if (round.roundnumber == 5) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round5.txt");
			round.round_init(5);
		}
	}
	else if (round.roundnumber == 6) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round6.txt");
			round.round_init(6);
		}
	}
	else if (round.roundnumber == 7) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round7.txt");
			round.round_init(7);
		}
	}
	else if (round.roundnumber == 8) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round8.txt");
			round.round_init(8);
		}
	}
	else if (round.roundnumber == 9) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round9.txt");
			round.round_init(9);
		}
	}
	else if (round.roundnumber == 10) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round10.txt");
			round.round_init(10);
		}
	}
	else if (round.roundnumber == 11) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round11.txt");
			round.round_init(11);
		}
	}
	else if (round.roundnumber == 12) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round12.txt");
			round.round_init(12);
		}
	}
	else if (round.roundnumber == 13) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round13.txt");
			round.round_init(13);
		}
	}
	else if (round.roundnumber == 14) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round14.txt");
			round.round_init(14);
		}
	}
	else if (round.roundnumber == 15) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round15.txt");
			round.round_init(15);
		}
	}
	else if (round.roundnumber == 16) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round16.txt");
			round.round_init(16);
		}
	}
	else if (round.roundnumber == 17) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round17.txt");
			round.round_init(17);
		}
	}
	else if (round.roundnumber == 18) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round18.txt");
			round.round_init(18);
		}
	}
	else if (round.roundnumber == 19) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round19.txt");
			round.round_init(19);
		}
	}
	else if (round.roundnumber == 20) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round20.txt");
			round.round_init(20);
		}
	}
	else if (round.roundnumber == 21) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round21.txt");
			round.round_init(21);
		}
	}
	else if (round.roundnumber == 22) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round22.txt");
			round.round_init(22);
		}
	}
	else if (round.roundnumber == 23) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round23.txt");
			round.round_init(23);
		}
	}
	else if (round.roundnumber == 24) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round24.txt");
			round.round_init(24);
		}
	}
	else if (round.roundnumber == 25) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round25.txt");
			round.round_init(25);
		}
	}
	else if (round.roundnumber == 26) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round26.txt");
			round.round_init(26);
		}
	}
	else if (round.roundnumber == 27) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round27.txt");
			round.round_init(27);
		}
	}
	else if (round.roundnumber == 28) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round28.txt");
			round.round_init(28);
		}
	}
	else if (round.roundnumber == 29) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round29.txt");
			round.round_init(29);
		}
	}
	else if (round.roundnumber == 30) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			round.round_start();
		}
		else {
			if (round.Set_round.brick_init)round.round_to_init("map/round30.txt");
			round.round_init(30);
		}
	}
	else if (round.roundnumber >= 31) {
		roundnumber = round.roundnumber;
		if (round.check_start) {
			if (boss.boss_heart > 0) {
				boss.Boss_start();
				round.boss_start(boss.Boss);
				boss.Boss_overlab(round.Ball.Ball, round.Play.player, round.Play.heart);
			}
			else {
				boss.Boss_dead();
				if (restrat_time == 900) {
					start = 1;
					round.game_end = 0;
					Menu = 0;
				}
				restrat_time++;
			}
		}
		else {
			boss.Boss_show();
			round.boss_init();
		}
	}
}
