#include <stdio.h>

int main()
{
	printf("### �޴��� ###\n");
	printf("1. �Ƹ޸�ī�� : 5000��\n");
	printf("2. ���� �� : 6000��\n");
	printf("3. ��ī �� : 8000��\n");
	printf("4. �ٴҶ� �� : 9000��\n");
	printf("5. ���ǳ� �� : 4000��\n");
	printf("9. �ֹ� ����\n");
	printf("############\n");

	int totalFee = 0;

	int num = 0;
	while (num != 9) {

		printf("�ֹ� ��ȣ�� �Է��� �ּ���. : ");
		scanf_s("%d", &num);

		switch (num)
		{
		case 1:
			totalFee += 5000;
			printf("�Ƹ޸�ī�� 1���� �ֹ� �߽��ϴ�.\n");
			break;
		case 2:
			totalFee += 6000;
			printf("���� �� 1���� �ֹ� �߽��ϴ�.\n");
			break;
		case 3:
			totalFee += 8000;
			printf("��ī �� 1���� �ֹ� �߽��ϴ�.\n");
			break;
		case 4:
			totalFee += 9000;
			printf("�ٴҶ� �� 1���� �ֹ� �߽��ϴ�.\n");
			break;
		case 5:
			totalFee += 4000;
			printf("���ǳ� �� 1���� �ֹ� �߽��ϴ�.\n");
			break;
		default:
			printf("�ֹ� ��ȣ�� Ȯ���Ͽ� �ֽñ� �ٶ��ϴ�.\n");
			break;
		}

	}
	printf("�ֹ��� �����մϴ�.\n");
	printf("�� ����ؾ��� ����� %d�� �Դϴ�.\n", totalFee);

}