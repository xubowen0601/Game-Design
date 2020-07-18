#include<iostream>
using namespace std;
int main(void)
{
	int a[] = { 10,20 };
	float b[] = { 205.5,103.5f };
	int* pa = a;
	float* pb = b;
	for (int i = 0; i < 2; i++)
	{
		cout << "pa中的地址为：" << pa + i << "\t其数值为：" << *pa + i << endl;
		cout << "pb中的地址为：" << pb + i << "\t其数值为：" << *pb + i << endl;
	}
	return 0;
}