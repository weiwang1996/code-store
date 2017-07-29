#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class A
{
public:

static bool PriNub(int val)
{
	for (int i = 2; i<val; ++i)
	{
		if (val%i == 0)
			return false;
	}
	return true;
}
static bool IsMagicNub(int val)
{
	vector<int> a;
	vector<int> b;
	vector<int> reasult;
	while (val)
	{
		a.push_back(val % 10);
		val =val/10;//153  3 5 1
	}
	for (int n = a.size()-1; n >=0 ; n--)
		b.push_back(a[n]);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (i == a.size() - 1 - j)
				continue;
			reasult.push_back(a[i] * 10 + b[j]);
		}
	}
	for (int idx = 0; idx < reasult.size(); idx++)
	{
		
		if (reasult[idx]>10&&PriNub(reasult[idx]))
			return true;
	}
	return false;
}
static int MagicNub(int lhs, int rhs)
{
	int count = 0;
	if (lhs<1 || lhs>rhs || rhs>10000)
		return 0;
	for (int i = lhs; i <= rhs; i++)
	{
	
		if (IsMagicNub(i))
		{
			count++;
		}
	}
	return count;
}

};

int main()
{
	int a,b;
	cin >> a;
	cin >> b;
cout<<A::MagicNub(a,b);
}
