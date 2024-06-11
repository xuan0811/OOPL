#include "stdafx.h"
#include "../Library/gameutil.h"
#include "round_init.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

INIT_func::INIT_func(){

}

void INIT_func::Loading_map(std::string round, int brick_id_round[], int brick[], int check_overlap[], CMovingBitmap brick_black[]) {
	int i = 0;
	std::ifstream ifs(round, std::ios::in);
	if (!ifs.is_open()) {
		cout << "Failed to open file.\n";
	}
	int coord;
	int heart;
	int id;
	while (ifs >> coord >> heart >>id) {
		brick[i] = heart;
		brick_id_round[i] = id;
		check_overlap[i] = 1;
		brick_black[brick_id_round[i++]].SetTopLeft(round_x[coord], round_y[coord]);
	}
	ifs.close();
}




void INIT_func::round_to_init(std::string round,int brick_id_round[], int brick[], int check_overlap[], CMovingBitmap brick_black[]) {
	Loading_map(round, brick_id_round,brick, check_overlap, brick_black);
	brick_init = 0;
}