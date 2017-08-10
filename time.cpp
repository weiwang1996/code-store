#include<iostream>
using namespace std;
class Time
{
public:
	Time()
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
	void show_time();
	void set_time(int _hour, int _minute, int _second);
private:
	int hour;
	int minute;
	int second;
};
void Time::set_time(int _hour, int _minute ,int _second)
{
	 hour=_hour;
	minute=_minute;
	second=_second;
}
void Time::show_time()
{
	cout << hour <<" : "<<minute<<" : "<<second<< endl;	
}
int main()
{
	Time t1;
	t1.set_time(12, 12, 12);
	t1.show_time(); 
	Time t2(3,20,20);
	t2.set_time(11, 11, 11);
	t2.show_time();
	return 0;
}