#define _CRT_SECURE_NO_WARNINGS

#include "TetrisHelper.h"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

#define GRID_WIDTH 7		//칸(행)
#define GRID_HEIGHT 10		//줄(열)
#define USERBLOCK_SIZE 3

int displayData[GRID_HEIGHT][GRID_WIDTH] = { 0, };

class Display {
public:
	//void draw() { // x,y 위치에 어떻게 출력 할지?
	//	for (int i = 0; i < GRID_HEIGHT; i++) {
	//		for (int k = 0; k < GRID_WIDTH; k++) {
	//			if (displayData[i][k] == 0) {
	//				drawPosition(k, i, false);
	//			}
	//			else {
	//				drawPosition(k, i, true);
	//			}
	//		}
	//	}
	//}
	void draw() {
		for (int i = 0; i < GRID_HEIGHT; i++) {
			for (int k = 0; k < GRID_WIDTH; k++) {
				drawPosition(k, i, displayData[i][k] == 1);
			}
		}
	}
};

class GameEngine {
public:
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = {
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0},
		{0,1,0,0,0,0,0},
		{1,1,0,0,0,0,0},
		{1,1,0,0,0,0,0}
	};
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = {
		{0,0,1},
		{0,0,1},
		{0,0,1}
	};

	int blockX = 0;		// 현재 유저블록의 위치를 기억하는 변수
	int blockY = 0;

	float elapsed = 0.0f;
	float controlCheck = 0.0f;

	void init() {
		//최초에 게임엔진을 초기화하는 함수
	}
	void next(float dt, char keyboardInput) {
		//키보드의 input 값을 받아와서 다음 할 일을 결정
		//while 무한루프에서 매번 불려짐
		//blockY++;
		elapsed = elapsed + dt;  // elapsed += dt;
		if (elapsed >= 0.5f) {
			if (canGoDown()) {
				blockY++;
			}
			else {
				//유저블록을 gameGridData 전사
				trans();
			}
			elapsed = elapsed - 0.5f;  // dlapsed -= dt;
		}
		controlCheck = controlCheck + dt;

		if (keyboardInput == 'a' && canGoLeft() && controlCheck > 0.1) {
			blockX--;
			controlCheck = 0.0f;
		}
		if (keyboardInput == 'd' && canGoRight() && controlCheck > 0.1) {
			blockX++;
			controlCheck = 0.0f;
		}
		if (keyboardInput == 's' && canGoDown() && controlCheck > 0.1) {
			blockY++;
			controlCheck = 0.0f;
		}
	}
	// 블록이 더 내려갈 수 있냐
	bool canGoDown() {
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (userBlock[i][k] == 1 && i + blockY + 1 >= GRID_HEIGHT)
					return false;
				if (userBlock[i][k] == 1 && gameGridData[i + blockY + 1][k + blockX] == 1)
					return false;
			}
		}
		return true;
	}

	bool isLineFilled(int y) { //y 번째 줄이 가득 차있는지
		for (int i = 0; i < GRID_WIDTH; i++) {
			if (gameGridData[y][i] == 0) return false;
		}
		return true;
	}

	void eraseLine(int y) { // y줄 지우기
		for (int i = 0; i < GRID_WIDTH; i++) {
			gameGridData[y][i] = 0;
		}
	}

	void drop(int y) {
		for (int i = y; i >= 0; i--) {
			for (int k = 0; k < GRID_WIDTH; k++) {
				gameGridData[i][k] = i - 1 < 0 ? 0 : gameGridData[i - 1][k];
			}
		}
	}

	//userBlock을 gameGrid에 전사하는 함수
	void trans() {
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				gameGridData[i + blockY][k + blockX] = userBlock[i][k] == 1 ? userBlock[i][k] : gameGridData[i + blockY][k + blockX];
			}
		}
		// 한줄이 가득 차 있는지 확인

		for (int i = 0; i < GRID_HEIGHT; i++) {
			if (isLineFilled(i)) {
				eraseLine(i);
				drop(i);
			}
		}

		//새로운 블록 생성
		makeUserBlock();
	}

	void makeUserBlock() {
		blockX = 0;
		blockY = 0;

		//todo: 랜덤 블록 생성
	}

	bool canGoLeft() {
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (userBlock[i][k] == 1 && k + blockX - 1 < 0) {
					return false;
				}
				if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX - 1] == 1) {
					return false;
				}
			}
		}
		return true;
	}

	bool canGoRight() {
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (userBlock[i][k] == 1 && k + blockX + 1 > GRID_WIDTH - 1) {
					return false;
				}
				if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX + 1]) {
					return false;
				}
			}
		}
		return true;
	}

	//실제 게임 데이터를 화면에 출력할 수 있는 데이터로 바꿔준다(조합)
	void makeDisplayData() {
		//그리드 데이터
		for (int i = 0; i < GRID_HEIGHT; i++) {
			for (int k = 0; k < GRID_WIDTH; k++) {
				displayData[i][k] = gameGridData[i][k];
			}
		}
		//유저블록 데이터
		for (int i = 0; i < USERBLOCK_SIZE; i++) {  // i는 줄 수
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (i + blockY < 0 || i + blockY > GRID_HEIGHT) {// i + blockY 블록의 y좌표
					//DO NOTHING								// i는 유저블록의 사이즈
				}
				else if (k + blockX < 0 || k + blockX > GRID_WIDTH) {
					//DO NOTHING
				}
				else {
					int _x = k + blockX;
					int _y = i + blockY;
					//TODO
					//displayData[i + blockY][k + blockX] = userBlock[i][k]; // 블록이 먹고 들어간다
					//displayData[i + blockY][k + blockX] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[i + blockY][k + blockX];
					displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x];//위 줄과 같은 연산을한다.
				}
			}
		}
	}
};