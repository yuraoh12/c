#include <iostream>
#include "Test.h"

int main() {

	Test t1(10, "aaa");
	t1.printStr();
	t1.printNo();
	t1.printArr();



	// °´Ã¼ º¹»ç
	//Test t3;
	//t3 = t1;

	Test t3 = Test(t1);

	t3.printStr();
	t3.printNo();
	t3.printArr();

	/*t3.printStr();
	t3.printNo();
	t3.printArr();

	t3.setNo(11);
	t3.setStr("kkk");
	t3.setArr(20);

	t3.printNo();
	t3.printStr();
	t3.printArr();

	t1.printNo();
	t1.printStr();
	t1.printArr();*/

}