#include <string>
#include "Date.h"
using namespace std;
class PhongKS
{
    private:
        string ID;
        int MaxPerson;
        bool Condition;
        Date Rday; // ngay nhan
        Date Pday;  //ngay tra
        double Price;
    public:
        PhongKS();
        ~PhongKS();
        void SetCondition(bool);
        void SetRday(Date);
        void SetPday(Date);
        double GetPrice();
        const string& GetID();
        friend ostream& operator<<(ostream &, const PhongKS&);
        friend istream& operator>>(istream& , PhongKS& );
        void Show();

};