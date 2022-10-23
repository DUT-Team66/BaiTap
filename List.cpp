#include <string>
#include "List.h"
#include <iostream>
using namespace std;
List::List()
{
    this->p=nullptr;
    this->n=0;
}
List::~List()
{
    delete[] this->p;
}
const int& List::Getlength()
{
    return this->n;
}
// Đa năng hóa toán tử []
PhongKS List::operator[](const int& index)
{
    PhongKS data;
    if (index>=0 && index<this->n)
        return *(this->p+index);  // Nếu gọi cú pháp: v.operator(x) thì con trỏ this sẽ chỉ đối tượng v
    else return data; // Khong co phan tu nao de tra ve
}                                                       
void List::Show()
{
    for (int i=0;i<this->n;i++)
    {
        cout<<"Phong thu "<<i+1<<endl;
        cout<<*(this->p+i)<<endl;  // Đã đa năng hóa
    }
    cout<<endl;
}

void List::AddFirst(const PhongKS & s)
{
    if(this->n==0) {
        this->p = new PhongKS[this->n+1];
        *(this->p+this->n) = s;
        this->n++;
    }
    else {
        PhongKS *temp = new PhongKS[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new PhongKS[this->n+1];
        *(this->p+0)=s;
        for (int i=1;i<=this->n;i++)
        {
            *(this->p+i)=*(temp+i-1);
        }
        delete[] temp;
        this->n++;
    }
}
void List::AddLast(const PhongKS & s)
{
    if(this->n==0) {
        this->p = new PhongKS[this->n+1];
        *(this->p+this->n) = s;
        this->n++;
    }
    else {
        PhongKS *temp = new PhongKS[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new PhongKS[this->n+1];
        for (int i=0;i<this->n;i++)  // còn phần tử cuối
            *(this->p+i)=*(temp+i);
        delete[] temp;
        *(this->p+this->n) = s;
        this->n++;
    }
}
void List::Insert(const PhongKS& s, int k)
{
    while (k<0 || k>=this->n){
        cout<<"Nhap lai vi tri k: ";
        cin>>k;
    }
    if (k==this->n-1) AddLast(s);
    else if (k==0) AddFirst(s);
    else {
        PhongKS *temp = new PhongKS[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new PhongKS[this->n+1];
        for (int i=0;i<k;i++)
        {
            *(this->p+i)=*(temp+i);
        }
        *(this->p+k) = s;
        for (int i=k+1;i<this->n+1;i++)
        {
            *(this->p+i) = *(temp+i-1);
        }
        delete[] temp;
        this->n++;
    }
}
void List::Update(string x)
{
    // Nhập mã phòng: mã phòng, số ngừoi tối đa, giá phòng không đổi-> Không cần cập nhật
    // Cần cập nhật tình trạng phòng, ngày nhận, ngày trả
    int index=-1;
    for (int i=0;i<this->n;i++)
    {
        if (x==(this->p+i)->GetID()) 
        {
            index=i;
            break;
        }
    }
    if (index>=0)
    {
        bool tinhtrangphong;
        cin>>tinhtrangphong;
        (this->p+index)->SetCondition(tinhtrangphong);
        if (tinhtrangphong==true) 
        {
            Date x(0,0,0);
            (this->p+index)->SetRday(x);
            (this->p+index)->SetPday(x);
        }
        else if (tinhtrangphong==false)
        {
            // Đa năng hóa toán tử >> trong Date
            Date ngaynhan;            
            cin>>ngaynhan;
            Date ngaytra;
            cin>>ngaytra;
            (this->p+index)->SetRday(ngaynhan);
            (this->p+index)->SetPday(ngaytra);
        }
    }
    else cout<<"Khong co phong nay!"<<endl;
}

void List::DeleteFirst()
{

    if (this->n==1) {
        delete[] this->p;
        this->p=nullptr;
        this->n--;
    }
    else {
        PhongKS *temp = new PhongKS[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
         }
        delete[] this->p;
        this->p = new PhongKS[this->n-1];
        for (int i=0;i<this->n-1;i++)
        {
            *(this->p+i)=*(temp+i+1);
        }
        delete[] temp;
        this->n--;
    }   
}


void List::DeleteLast()
{
    if (this->n==1) {
        delete[] this->p;
        this->p=nullptr;
        this->n--;
    }
    else {
        PhongKS *temp = new PhongKS[this->n];
        for (int i=0;i<this->n;i++)
        {
            *(temp+i) = *(this->p+i);
         }
        delete[] this->p;
        this->p = new PhongKS[this->n-1];
        for (int i=0;i<this->n-1;i++)
        {
            *(this->p+i)=*(temp+i);
        }
        delete[] temp;
        this->n--;
    } 
}
void List::Delete(int index)
{
if (index>=0 && index<this->n)
    {
        if (this->n==1) {
        delete[] this->p;
        this->p=nullptr;
        this->n--;
        }
    else {
        PhongKS *temp = new PhongKS[this->n];
            for (int i=0;i<this->n;i++)
            {
                *(temp+i) = *(this->p+i);
            }
            delete[] this->p;
            this->p = new PhongKS[this->n-1];
            for (int i=0;i<index;i++){
                *(this->p+i) = *(temp+i);
            }
            for (int i=index; i<this->n-1;i++){
                *(this->p+i)=*(temp+i+1);
            }
            delete[] temp;
            this->n--;
    }
}
}
bool ascending(double left, double right)
{
    return left<right;
}
bool descending(double left,double right)
{
    return left>right;
}

void List::Merge( int left, int mid, int right, bool (*ComFunc)(double , double ) )
{
    PhongKS *temp = new PhongKS[right-left + 1];
    int i = left, j = mid + 1;
    for (int k = 0; k <= right - left; k++)
    {
        if ( ComFunc((this->p+i)->GetPrice(),(this->p+j)->GetPrice()) )// Sap xep tang dan
        {
            *(temp + k) = *(this->p+i);
            i++;
        }
        else
        {
            *(temp + k) = *(this->p+j);
            j++;
        }
        if (i == mid + 1)
        {
            while (j <= right)
            {
                k++;
                *(temp + k) = *(this->p+j);
                j++;
            }
            break;
        }
        if (j == right + 1)
        {
            while (i <= mid)
            {
                k++;
                *(temp + k) = *(this->p+i);
                i++;
            }
            break;
        }
    }
    for (int k = 0; k <= right- left; k++)
        *(this->p + left + k) = *(temp + k);
    delete temp;
}

void List::MergeSort1(int left, int right) // Sắp xếp tăng dần
{
    if (right>left)
    {
        int mid=(left+right)/2;
        MergeSort1(left,mid);
        MergeSort1(mid+1,right);
        Merge(left,mid,right,ascending);
    }
}

void List::MergeSort2(int left, int right) // Sắp xếp giảm dần
{
    if (right>left)
    {
        int mid=(left+right)/2;
        MergeSort2(left,mid);
        MergeSort2(mid+1,right);
        Merge(left,mid,right,descending);
    }
}

int List::InterpolationSearch(double x)
{
    MergeSort1(0,this->n);
    int left = 0;
    int right = this->n-1;
    while (left <= right && x >= (this->p+left)->GetPrice() && x <= (this->p+right)->GetPrice())
    {
        double val1 = (double) (x - (this->p+left)->GetPrice()) / ((this->p+right)->GetPrice()-(this->p+left)->GetPrice());
        int val2 = (right-left);
        int pos = left + val1*val2;

        if ((this->p+pos)->GetPrice() == x)
            return pos;

        if ((this->p+pos)->GetPrice() < x)
        left = pos + 1;
        else
        right = pos - 1;
    }
    return -1;
} 
void List::Search(double x)
{
    int index=InterpolationSearch(x);
    if (index<0) cout<<"Khong co phong can tim!"<<endl;
    else 
        cout<<*(this->p+index);
}
