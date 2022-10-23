#include "PhongKS.h"
#include <string>
#include <iostream>
using namespace std;
PhongKS::PhongKS()
{
    this->ID="";
    this->MaxPerson=0;
    Condition=true;
    Date x(0,0,0);
    Rday=x;
    Pday=x;
    Price=0.0;
}
PhongKS::~PhongKS()
{

}

const string& PhongKS::GetID()
{
    return this->ID;
}
void PhongKS::SetCondition(bool x)
{
    this->Condition=x;
}
void PhongKS::SetRday(Date x)
{ 
    // Cần đa năng hóa toán tử gán =
    // Date khong co con tro nen co the gan duoc
    this->Rday=x;
}
void PhongKS::SetPday(Date x)
{
    this->Pday=x;
}
double PhongKS::GetPrice()
{
    return this->Price;
}
ostream& operator<<(ostream& out, const PhongKS& p) 
{
    out<<"Maphong: "<<p.ID<<endl<<"So nguoi toi da: "<<p.MaxPerson<<endl<<"Tinh trang phong:  ";
    if (p.Condition==true) out<<"phong trong" ;
    else out<<"da co nguoi o";
    out<<endl<<"Ngay nhan phong: ";
    if (p.Condition==true) out<<"NULL"<<endl<<"Ngay tra phong: NULL";
    else out<<p.Rday<<endl<<"Ngay tra phong: "<<p.Pday;
    out<<endl<<"Gia phong: "<<p.Price<<endl;
    return out; // Nếu gọi hàm: o sẽ xuất ra mấy cái đã hấp thụ
}
istream& operator>>(istream& in, PhongKS& p)
{
    cout<<"Nhap ma phong: ";
    in>>p.ID;
    while ( p.ID[0]<'1' || p.ID[0]>'5' || p.ID.size() !=5)
    {
        cout<<"Nhap lai ma phong: ";
        in>>p.ID;
    }
    cout<<"Nhap so nguoi toi da: ";
    in>>p.MaxPerson;
    while ( p.MaxPerson<1 && p.MaxPerson>4)
    {
        cout<<"Nhap lai so nguoi toi da: ";
        in>>p.MaxPerson;
    }
    cout<<"Nhap tinh trang phong: "; //true or false
    in>>p.Condition;
    if (p.Condition ==true )
    {
        Date x(0,0,0);
        p.SetRday(x);
        p.SetPday(x);
        cout<<"Ngay nhan phong: NULL";
        cout<<endl<<"Ngay tra phong: NULL"<<endl;
        break;
    }
    else if (p.Condition==false)
    {
        cout<<"Nhap ngay nhan phong: ";
        in>>p.Rday;
        cout<<"Nhap ngay tra phong: ";
        in>>p.Pday;
        break;
    }
    cout<<"Nhap gia phong: ";
    in>>p.Price;
    return in;
}
