#include<iostream>
#include<string.h>
using namespace std;
//template<class T>
//T Add(T left, T right)
//{
//	cout << "模板生成的Add" << endl;
//	return left + right;
//}
//int Add(int left, int right)
//{
//	cout << "自己的函数" << endl;
//	return left + right;
//}
//template<>
// double Add< double>(double p1,  double p2)
//{
//	return p1+p2;
//}
//int main()
//{
//	cout << Add(1.1, 2.2) << endl;
//	return 0;
//}
template<class T>
class Seqlist
{
public:
	Seqlist()
		:_size(0)
		, _capacity(10)
		, _data(new T[_capacity])
	{}
	~Seqlist()
	{
	//	delete[]_data;
	}
private:
	T *_data;
	int _size;
	int _capacity;
};
int main()
{
	Seqlist<int> s;
	return 0;
}