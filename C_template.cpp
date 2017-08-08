#include<stdio.h>
typedef double TYPE;
TYPE Add(void *left, void* right)
{
	return *(TYPE*)left + *(TYPE*)right;
}
int main()
{
	double a=5.3, b = 7.6;
	void *x = (void*)&a;
	void *y = (void*)&b;
	printf("%f\n", Add(x, y));
}