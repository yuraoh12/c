#include "Header.h"

#define INTERVAL 1.0/60.0

int main() {

	float prev = (float)clock() / CLOCKS_PER_SEC;
	//clock() 이 프로그램 시작된 순간부터 계속 시간을 구한다.
	Display* display = new Display();
	GameEngine* gameEngine = new GameEngine();
	showConsoleCursor(false); // 언더바 지우는 함수

	while (true) {
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float dt = curr - prev;

		if (dt < INTERVAL) continue;  // 우리가 정해준 1/60 초 보다 작다면? 루프의 처음으로 
		prev = curr;

		//printf("%.3f\n", curr);

		bool left = keyState('a');
		bool right = keyState('d');
		bool down = keyState('s');
		if (left) {
			//왼쪽으로 블록을 이동시킨다.
			gameEngine->next(dt, 'a');
		}
		else if (right) {
			gameEngine->next(dt, 'd');
		}
		else if (down) {
			gameEngine->next(dt, 's');
		}
		else {
			//그냥 떨어진다.
			gameEngine->next(dt, 0);
		}

		/*gameEngine->next(dt, 0);*/
		//화면에 출력
		gameEngine->makeDisplayData();
		display->draw();
		//게임상태를 판별
	}


	return 0;
}