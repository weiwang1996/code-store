#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year=1970,int month=1,int day=1)//���캯��
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if (!Check_Date())
		{
			cout << "�Ƿ����ڣ�" << endl;
			exit(0);
		}
	}
	Date(const Date&d);//�������캯��
	Date& operator=(const Date& d);//��ֵ���������
	friend ostream& operator<<(ostream& _cout,Date& d);//���������
	Date operator-(int days);//��ȥһ��ʱ��
	Date operator+(int days);//����һ��ʱ��
	int operator-(const Date& d);//����֮����������
	//Date& operator++();//ǰ�üӼ�
	//Date operator++(int);//���üӼ�
	//Date& operator--();
	//Date operator--(int);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	void Display();//��ʾ����
	int Month_day(int year,int month);//�鿴��ǰ���ж�����
	bool Check_Date();//��������Ƿ�Ϊ�ϸ�����
	bool  IsLeap()
	{
		if (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400) == 0)
			return true;
		else
			return false;
	}
private:
	int _year;
	int _month;
	int _day;
};
int Date::Month_day(int year,int month)
{
	int DayOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400) == 0)
	{
		if (month == 2)
			return DayOfMonth[month] + 1;
		else
			return DayOfMonth[month];
	}
		else
			return DayOfMonth[month];
	
}
Date::Date(const Date&d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
ostream& operator<<(ostream& _cout, Date& d)
{
	_cout << d._year << "��" << d._month << "��" << d._day << "��";
	return _cout;
}
Date Date::operator-(int days)
{
	Date temp(*this);
	if (days>0)
	{
		temp._day = temp._day - days;
		while (temp._day<=0)
		{
			if (temp._month == 1)
			{
				temp._month = 12;
				temp._year -= 1;
			}
			else
				temp._month -= 1;
			temp._day =temp._day+ Month_day(temp._year, temp._month);
		}
	}
	else if (days<0)
	{
		return (*this) +(-days);
	}
	return temp;
}
int Date::operator-(const Date& d)
{
	int count = 0;
	Date FutureDate;
	Date PastDate;
	if (*this > d)
	{
		FutureDate=*this;
		PastDate=d;
	}
	else
	{
		FutureDate = d;
		PastDate =*this;
	}
	while (FutureDate != PastDate)
	{
		PastDate = PastDate+1;
		count++;
	}
	return count;
}
bool Date::operator>(const Date&d)
{
	if ((_year <= d._year) && (_month <= d._month) && (_day <= d._day))
		return false;
	else
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
			return false;
			return true;
	}
}
bool Date::operator<(const Date&d)
{
	if ((_year >= d._year) && (_month >= d._month) && (_day >= d._day))
		return false;
	else
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
			return false;
		return true;
	}
}
bool Date::operator==(const Date& d)
{
	if ((_year == d._year) && (_month == d._month) && (_day == d._day))
		return true;
	else
		return false;
}
bool Date::operator!=(const Date& d)
{
	if ((_year == d._year) && (_month == d._month) && (_day == d._day))
		return false;
	else
		return true;
}
Date Date::operator+(int days)
{
	Date temp(*this);
	if (days < 0)
	{
		return *this - (-days);
	}
	else if (days>=0)
	{
		temp._day = temp._day + days;
		while (temp._day>Month_day(temp._year, temp._month))
		{
			temp._day = temp._day - Month_day(temp._year, temp._month);
			if (temp._month == 12)
			{
				temp._month = 1;
				temp._year += 1;
			}
			else
				temp._month += 1;
		}
	}
	return temp;
}
bool Date::Check_Date()
{
	if (_year > 0)
	{
		if (_month > 0 && _month <= 12)
		{
			if (_day > 0 && (_day <= Month_day(_year,_month)))
				return true;
		}
	}
	return false;
}
void Date::Display()
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
}
int main()
{
	Date d1(2017, 4, 26);
	Date d2;
	Date d3(2016,4,26);
	//Date d2(1000, 2, 11);
	//int ret = d1.Month_day();
	//cout << ret<<endl;
	 d2 = d1;
	/*d1.Display();
	d2.Display();
	d3.Display();*/
	/*cout << d1<<endl;
	d3 = d1 + 999;
	cout << d3 << endl;*/
	 int count = d3 - d1;
	 cout << count;
	return 0;
}