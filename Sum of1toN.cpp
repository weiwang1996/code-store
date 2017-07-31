#include<iostream>
using namespace std;
//int GetSumByCir(size_t N)//∆’Õ®—≠ª∑
//{
//	int sum = 0;
//	for (int idx = 1; idx <=N; idx++)
//	{
//		sum += idx;
//	}
//	return sum;
//}
int GetSumByRec(size_t N)//µ›πÈ∞Ê
{
	if (N==1)
	     return 1;
	else 
		return N + GetSumByRec(N - 1);
}
template<size_t N>
size_t F()
{
	return N + F<N - 1>();
};
template<>
size_t F<1>()
{
	return 1;
};
void TestGetValueByTemplate()
{
	cout << F<1000>() << endl;
}


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
int Test::count = 0;
int Test::sum = 0;
int main()
{
	Test *p = new Test[100];
	delete[] p;
	cout << Test::getsum();
}
class AA;
AA* Array[2];
class AA
{
public:
	virtual size_t Sum(size_t n)
	{
		return 0;
	}
};

class BB :public AA
{
public:
	virtual size_t Sum(size_t n)
	{
		return Array[!n]->Sum(n - 1) + n;
	}
};

int GetValueByVirtual(size_t n)
{
	AA a;
	BB b;
	Array[0] = &b;
	Array[1] = &a;

	int value = Array[0]->Sum(n);
	return value;
}

void TestGetValueByVirtual()
{
	cout << GetValueByVirtual(5) << endl;
}
int main()
{
	TestGetValueByVirtual();
}
//int main()
//{
//	//int ret = GetSumByCir(100);
//	//long ret = GetSumByRec(5000);
//	//cout << ret << endl;
//	TestGetValueByTemplate();
//	return 0;
//}