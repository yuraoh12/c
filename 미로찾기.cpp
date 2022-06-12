#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int maze_board[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 9, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int player_x = 1;
int player_y = 1;

int is_clear = 0; // 0. 진행, 1. 클리어

void print_maze() {


	//    +
	//    +
	//+ + p + +
	//    +
	//    +


	int hstart = player_x - 2;
	int hend = player_x + 2;

	if (hstart < 0) {
		hstart = 0;
	}
	if (hend >= 10) {
		hend = 10;
	}

	int vstart = player_y - 2;
	int vend = player_y + 2;

	if (vstart < 0) {
		vstart = 0;
	}
	if (vend >= 10) {
		vend = 10;
	}

	for (int row = vstart; row < vend; row++) {
		for (int col = hstart; col < hend; col++) {
			if (maze_board[row][col] == 1) {
				printf("■");
			}
			else if (maze_board[row][col] == 2) {
				printf("☆");
			}
			else if (maze_board[row][col] == 9) {
				printf("♥");
			}
			else if (maze_board[row][col] == 0) {
				printf("  ");
			}
		}
		printf("\n");
	}
}

void player_move(int y, int x) {
	int destination_x = player_x + x;
	int destination_y = player_y + y;


	if (maze_board[destination_y][destination_x] == 9) {
		is_clear = 1;
	}
	else if (maze_board[destination_y][destination_x] != 1) {

		maze_board[player_y][player_x] = 0;
		maze_board[destination_y][destination_x] = 2;

		player_x = destination_x;
		player_y = destination_y;

	}
}

void input_move() {
	char key = _getch();

	if (key == 's') {
		player_move(1, 0);
	}
	else if (key == 'w') {
		player_move(-1, 0);
	}
	else if (key == 'a') {
		player_move(0, -1);
	}
	else if (key == 'd') {
		player_move(0, 1);
	}
}

int main(void) {

	print_maze();

	for (int i = 0; ; i++) {
		input_move();

		if (is_clear == 1) {
			break;
		}

		system("cls");
		print_maze();


	}

	return 0;
}