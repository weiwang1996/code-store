#include<stack>
#include<iostream>
using namespace std;
bool StackPushPopOrder(int *push,int *pop,int length)
{
	if (push == NULL || pop == NULL || length < 0)
		return false;
	stack<int> spop;
	int *nextpush = push;
	int *nextpop = pop;
	while (nextpop-pop<length)//ֱ��������nextpush�е�Ԫ��
	{
		while (spop.empty()||spop.top()!=*nextpop)
		{
			if (nextpush - push == length)//�ߵ��ò���˵��nextpush�ߵ�ͷ��û�ҵ�ֱ���˳�
				break;
			spop.push(*nextpush);
			nextpush++;
		}
		if (spop.top() == *nextpop)//�ҵ���ȵ�nextpop����ƣ�ͬʱpopջ��Ԫ��
		{
			nextpop++;
			spop.pop();
		}
		else break;
	}
	if (spop.empty() && nextpush - push == length)
		return true;
	return false;
}
void TestFun()
{
	int push[] = {1,2,3,4,5};
	int pop1[] = {4,5,3,2,1};
	int pop2[] = { 4, 3, 5, 1, 2 };
	int pop3[] = { 5, 4, 3, 2, 1 };
	cout << StackPushPopOrder(push, pop1, 5)<<endl;
	cout << StackPushPopOrder(push, pop2, 5)<<endl;
	cout << StackPushPopOrder(push, pop3, 5)<<endl;
}
int main()
{
	TestFun();
	return 0;
}