#include<iostream>
using namespace std;
class ObjInHeap
{
public:
	static ObjInHeap* GetObject(int aa)//new的对象生命周期长用引用接受
	{
		return new ObjInHeap(aa);
	}
	~ObjInHeap()
	{
		delete this;
	}
	int get()
	{
		return _aa;
	}
protected:
	ObjInHeap(int aa)
		:_aa(aa)
	{}
	ObjInHeap(ObjInHeap&);
	ObjInHeap& operator=(ObjInHeap);
	int _aa;
};
//ObjInHeap ww(1);
int main()
{
	//ObjInHeap aa(10);限制在栈上创建对象
	ObjInHeap *aa = ObjInHeap::GetObject(1);//把成员函数设置为static，就能不需要对象能调用成员函数。
	cout << aa->get() << endl;
	system("pause");
	return 0;
}//struct AA
//{
//	int a;
//	int b;
//	static AA& GetObject(int a, int b)
//	{
//		return *new AA(a, b);
//	}
//	~AA()
//	{
//		delete this;
//	}
//protected:
//	AA(int a, int b)
//		:a(a)
//		, b(b)
//	{}
//};
//int main()
//{
//	//AA a(1,2);  
//	AA a = AA::GetObject(1, 2);
//	cout << a.a << " " << a.b << endl;
//	system("pause");
//	return 0;
//}