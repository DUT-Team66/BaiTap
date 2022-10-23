#include <iostream>
#include <string>
#include "List.h"
using namespace std;
int main()
{
    List ks;
    while (true)
    {
        string enter; // thực hiện tiếp công việc
        cout<<"1. Hien thi danh sach doi tuong"<<endl;
        cout<<"2.Them doi tuong PhongKS"<<endl;
        cout<<"3.Cap nhat thong tin doi tuong"<<endl;
        cout<<"4.Xoa doi tuong"<<endl;
        cout<<"5.Tim kiem doi tuong PhongKS theo gia phong Price"<<endl;
        cout<<"6. Sap xep mang cac doi tuong PhongKS theo gia phong Price tang dan hoac giam dan:"<<endl;
        cout<<"Nhap lua chon: ";

        int opt1;
        cin>>opt1;

        while ( opt1 != 1 && opt1 != 2 && opt1 != 3 && opt1 != 4 && opt1 != 5 && opt1 != 6)
        {
            cout << "Nhap lai lua chon: " ;
            cin >> opt1;
        }

        if (opt1==1) ks.Show();
        if (opt1==2) 
        {
            PhongKS s;
            cin>>s;
            cout<<"1. Them dau mang"<<endl;
            cout<<"2.Them cuoi mang"<<endl;
            cout<<"3.Them vi tri k bat ki"<<endl;
            int opt2;
            cin>>opt2;
            while ( opt2 != 1 && opt2 != 2 && opt2 != 3 )
            {
                cout << "Nhap lai lua chon: " ;
                cin >> opt2;
            }
            if (opt2==1) ks.AddFirst(s);
            else if (opt2==2) ks.AddLast(s);
            else if (opt2==3)
            {
                int k;
                cout<<"Nhap vi tri can them: ";
                cin>>k;
                ks.Insert(s,k);
            } 
        }
        if (opt1==3)
        {
            string m;
            cout<<"Nhap ma phong can cap nhat: ";
            getline(cin,m);
            ks.Update(m);
        }
        if (opt1==4)
        {
            cout<<"1. Xoa dau mang"<<endl;
            cout<<"2.Xoa cuoi mang"<<endl;
            cout<<"3.Xoa vi tri k bat ki"<<endl;
            int opt2;
            cin>>opt2;
            while ( opt2 != 1 && opt2 != 2 && opt2 != 3 )
            {
                cout << "Nhap lai lua chon: " ;
                cin >> opt2;
            }
            if (opt2==1) ks.DeleteFirst();
            else if (opt2==2) ks.DeleteLast();
            else if (opt2==3)
            {
                int k;
                cout<<"Nhap vi tri can xoa";
                ks.Delete(k);
            }
        
        }
        if (opt1==5)
        {
            double x ;
            cout<<"Nhap gia phong can tim: ";
            cin>>x;
            ks.Search(x);
        }
        if (opt1==6)
        {
            int opt2;
            cout<<"1.Sap xep tang dan"<<endl;
            cout<<"2.Sap xep giam dan"<<endl;
            cout<<"Nhap lua chon: ";
            cin>>opt2;
            while ( opt2 != 1 && opt2 != 2 )
            {
                cout << "Nhap lai lua chon: " ;
                cin >> opt2;
            }
            if (opt2==1) ks.MergeSort1(0,ks.Getlength()-1);
            else if (opt2==2) ks.MergeSort2(0,ks.Getlength()-1);
        }

        cout<<"An C de tiep tuc"<<endl;
        cout<<"An B de thoat"<<endl;
        cout<<"Nhap lua chon: ";
        cin>>enter;
        while (enter != "C" && enter != "B")
        {
            cout << "Nhap lai lua chon: " ;
            cin >> enter;
        }
        if (enter=="B") break;
        else if (enter=="C") continue;
    }
    return 0;
}