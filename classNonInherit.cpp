#include<iostream>
using namespace std;
//第一种方法，封装构造函数，给出static接口，在继承的时候，
//派生类构造函数的初始化列表上调基类的构造函数，调不到
//从而防止继承，但是这种方法只能在堆上产生对象，不能再栈上产生对象，有弊端
//class NonInherit
//{
//public:
//	static NonInherit* GetObj(int a)
//	{
//		return new NonInherit(a);
//	}
//private:
//	NonInherit(int a)
//		:_a(a)
//	{}
//	~NonInherit()
//	{}
//	int _a;
//};
//class B :public NonInherit
//{
//public :
//	B()
//	:_b(0)
//	{}
//private:
//	int _b;
//};
//int main()
//{
//	NonInherit* p=NonInherit::GetObj(5);
//	return 0;
//}
//虚拟继承
template<typename T>
class Makesealed
{
	friend T;
private:
	Makesealed(){}
	~Makesealed(){}
};
class SealedClass : virtual public Makesealed<SealedClass>
{
public:
	SealedClass(){}
	~SealedClass(){}
};
class Try:public SealedClass
{
public:
	Try(){}
	~Try(){}
};
int main()
{
	SealedClass sea;
	Try try;
	return 0;
}

