#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
bool Increment(char *arr)
{
	int length = strlen(arr);
	int Takeover = 0;//������λ
	for (int i = length - 1; i >= 0; i--)
	{
		//�ж�ÿһλ�ϸ�
		int num = arr[i] - '0' + Takeover;//��λ�ַ�-��0��+��λ������Takeover
		if (i == length - 1)
			num++;
		if (num > 9)
		{
			if (i == 0)//˵�����λΪ10Խ��
				return false;
			num -= 10;
			Takeover = 1;
			arr[i] = '0' + num;
		}
		else
		{
			arr[i] = num + '0';
			break;
		}
	}
	return true;
}
void Print(char* arr)
{
	bool begining0 = true;
	int length = strlen(arr);
	for (int i = 0; i<length; ++i)
	{
		if (begining0&&arr[i] != '0')
			begining0 = false;
		if (!begining0)
		{
			printf("%c", arr[i]);
		}
	}
	cout << "  ";
}
void Print1ToMaxOfNDigits(int n)
{
	assert(n > 0);
	char * arr = new char[n+1];
	memset(arr, '0', n);
	arr[n] = '\0';
	while (Increment(arr))
		Print(arr);
	delete[]arr;
}
int main()
{
	Print1ToMaxOfNDigits(3);
	return 0;
}