#include<stdio.h>

main() {
	int val[7] = { 78,95,88,85,80,79,85 };
	int x;
	printf("data :");
	for (x = 0; x < 7; x++) {
		printf("%5d", val[x]);
	}
	printf("\n");
	//��հ���ؼ� ���
	int tot = 0;
	for (x = 0; x < 7; x++) {
		tot += val[x];
	}
	int ave = tot / 7.;
	printf("���:%5d\n", ave);

	int min = (val[0] > ave) ? val[0] - ave : ave - val[0];
	int minvalue = val[0];
	for (x = 1; x < 7; x++) {
		int temp;
		if (val[x] > ave) {
			temp = val[x] - ave; 
		}
		else {
			temp = ave - val[x];
		}
		if (min > temp) {
			min = temp;
			minvalue = val[x];
		}
	}
	printf("��հ��� ���� ����� ��", minvalue);
}