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
	while (nextpop-pop<length)//直到查找完nextpush中的元素
	{
		while (spop.empty()||spop.top()!=*nextpop)
		{
			if (nextpush - push == length)//走到该步，说明nextpush走到头还没找到直接退出
				break;
			spop.push(*nextpush);
			nextpush++;
		}
		if (spop.top() == *nextpop)//找到相等的nextpop向后移，同时pop栈顶元素
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