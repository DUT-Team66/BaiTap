#include <iostream>
using namespace std;
class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int, int , int );
        Date (const Date&);
        ~Date();
        friend ostream& operator<<(ostream &, const Date&);
        friend istream& operator>>(istream& , Date& );
};

