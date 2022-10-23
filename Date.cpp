#include "Date.h"
#include <iostream>
using namespace std;
Date::Date()
{

}
Date::Date(int x, int y, int z)
: day(x), month(y), year(z)
{

}
Date::Date(const Date& x)
{
    this->day=x.day;
    this->month=x.month;
    this->year=x.year;
}
Date::~Date()
{

}
ostream& operator<<(ostream& o, const Date& p) 
{
    o<<p.day<<"/"<<p.month<<"/"<<p.year; 
    return o; 
}
istream& operator>>(istream& in, Date& p)
{
    cout<<"\t\tNgay: ";
    in>>p.day;
    cout<<"\t\tThang: ";
    in >> p.month;
    cout<<"\t\tNam: ";
    in>>p.year;
    return in;
}
