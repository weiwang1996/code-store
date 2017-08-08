#include<iostream>
#include<assert.h>
using namespace std;
//时间复杂度O(2^N)
long long Fibonacci(unsigned n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//时间复杂度N
/*long long Fibonacci(unsigned n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];
	long long Fibnasecond = 1;
	long long Fibnafirst = 0;
	long long FibN = 0;
	for (unsigned i = 2; i <= n; ++i)
	{
		FibN = Fibnafirst + Fibnasecond;
		Fibnafirst = Fibnasecond;//把第二个给第一个数
		Fibnasecond = FibN;//把第三个数给第二个
	}
	return FibN;
}*/
//时间复杂度 O(lgN),空间复杂度N
void BobbleSort(int *arr,  int length)
{
	if (arr == NULL || length <= 1)
		return;
	for (int i = 0; i < length-1 ; i++)
	{
		for (int j = 0; j < length - i-1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				std::swap(arr[j], arr[j+1]);
			}
		}
	}
}
void TestSort()
{
	int arr[] = { 1, 5, 6, 2, 3, 4, 7, 8, 9 };
	BobbleSort(arr, 9);
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i]<<"  ";
	}
}
int BinSearch(int * arr, int k,size_t n)
{
	assert(arr);
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int mid = left+(right-left) / 2;
		if (k>arr[mid])
		{
			left = mid;
		}
		else if (k < arr[mid])
		{
			right = mid;
		}
		else
			return mid;
	}
	if (left>right)
		return -1;
}
//时间复杂度N^2，空间复杂度N
int BinSearch(int * arr, int k,int left,int right)
{
	assert(arr);
	int mid = 0;
	if (left <= right)
	{
		mid = (right + left) / 2;
		if (k == arr[mid])
			return mid;
		else if (k > arr[mid])
			return BinSearch(arr, k, mid+1, right);
		else if (k < arr[mid])
			return BinSearch(arr, k, left-1, mid);
	}
	else return -1;
}
int main()
{
	TestSort();
	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int ret = BinSearch(arr, 5, sizeof(arr)/sizeof(arr[1]));
	//int ret = BinSearch(arr, 11, 0, 8);
	//cout << ret << endl;
	return 0;
}
//时间复杂度N
class Test
{
public:
	Test()
	{
		count++;
		sum += count;
	}
	static int getsum()
	{
		return sum;
	}
public:
	static int count;
	static int sum;
};
int Test :: count = 0;
int Test::sum = 0;
/*int main()
{
	Test *p=new Test[100];
	delete[] p;
	cout << Test::getsum();
}*/
