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
		cout << "pa�еĵ�ַΪ��" << pa + i << "\t����ֵΪ��" << *pa + i << endl;
		cout << "pb�еĵ�ַΪ��" << pb + i << "\t����ֵΪ��" << *pb + i << endl;
	}
	return 0;
}