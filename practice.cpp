#include <stdio.h>

int main()
{
	printf("### 메뉴판 ###\n");
	printf("1. 아메리카노 : 5000원\n");
	printf("2. 녹차 라떼 : 6000원\n");
	printf("3. 모카 라떼 : 8000원\n");
	printf("4. 바닐라 라떼 : 9000원\n");
	printf("5. 토피넛 라떼 : 4000원\n");
	printf("9. 주문 종료\n");
	printf("############\n");

	int totalFee = 0;

	int num = 0;
	while (num != 9) {

		printf("주문 번호를 입력해 주세요. : ");
		scanf_s("%d", &num);

		switch (num)
		{
		case 1:
			totalFee += 5000;
			printf("아메리카노 1잔을 주문 했습니다.\n");
			break;
		case 2:
			totalFee += 6000;
			printf("녹차 라떼 1잔을 주문 했습니다.\n");
			break;
		case 3:
			totalFee += 8000;
			printf("모카 라떼 1잔을 주문 했습니다.\n");
			break;
		case 4:
			totalFee += 9000;
			printf("바닐라 라떼 1잔을 주문 했습니다.\n");
			break;
		case 5:
			totalFee += 4000;
			printf("토피넛 라떼 1잔을 주문 했습니다.\n");
			break;
		default:
			printf("주문 번호를 확인하여 주시기 바랍니다.\n");
			break;
		}

	}
	printf("주문을 종료합니다.\n");
	printf("총 계산해야할 비용은 %d원 입니다.\n", totalFee);

}