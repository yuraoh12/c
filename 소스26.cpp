#include <cstdio>
#include <string>

template <typename T>
class MyArray {
public:
	T* arrayItem; //�迭������
	int count = 0;
	int capacity = 8;

	MyArray() {
		arrayItem = new T[capacity];
	}
	virtual ~MyArray() {
		delete[] arrayItem;
	}
	void putValue(T value) {
		if (capacity > count) { //count�� �迭�� �ε����̹Ƿ� �����Ǵ� ��� �̹Ƿ� ���ܽ�����
			arrayItem[count] = value;
			count++;
		}
		else {
			printf("�迭�� ũ��(capacity)�� �ι�� �þ\n");
			T* newarray = new T[capacity * 2];
			capacity = capacity * 2; 
			for (int i = 0; i < count; i++) {
				newarray[i] = arrayItem[i];
			} 
			arrayItem = newarray;
			arrayItem[count] = value;
			count++;
		}
	}
};
int main() {
	MyArray<int> m = MyArray<int>();
	m.putValue(100);
	m.putValue(200);
	m.putValue(300);
	m.putValue(400);
	m.putValue(500);
	m.putValue(600);
	m.putValue(700);
	m.putValue(800);
	m.putValue(900);

	for (int i = 0; i < m.count; i++) {
		printf("%d ", m.arrayItem[i]);
	}
	return 0;
}