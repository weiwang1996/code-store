#include<iostream>
using namespace std;
//��һ�ַ�������װ���캯��������static�ӿڣ��ڼ̳е�ʱ��
//�����๹�캯���ĳ�ʼ���б��ϵ�����Ĺ��캯����������
//�Ӷ���ֹ�̳У��������ַ���ֻ���ڶ��ϲ������󣬲�����ջ�ϲ��������б׶�
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
//����̳�
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

