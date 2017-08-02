#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
bool IsSpace(int x)
{
	if (x == ' ' || x == '\n' || x == '\t' || x == '\f' || x == '\r')
		return true;
	else
		return false;
}
bool IsDigit(int x)
{
	if (x <= '9'&&x >= '0')
		return true;
	else
		return false;
}
int Myatoi(char* str)
{
	assert(str);
	int cur=0;
	int sign=0;
	int total=0;
	while (IsSpace((int)(unsigned char)*str))
		++str;
	cur = (int)(unsigned char)*str++;//取第一个字符 判断是不是 '+' 或者 '-'
	sign = cur;
	if (sign=='-'||sign=='+')
		cur = (int)(unsigned char)*str++;
	while (IsDigit(cur))
	{
		total = 10 * total + (cur - '0');
		cur = (int)(unsigned char)*str++;
	}
	if (sign == '-')
		return -total;
	else
		return total;
}
void Test()
{
	char* str = "  \n\r-1 2l3hj";
	cout << atoi(str) << endl;
	cout << Myatoi(str) << endl;
}
int main()
{
	Test();
	return 0;
}