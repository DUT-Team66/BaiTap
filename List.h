#include <string>
#include "PhongKS.h"
using namespace std;
class List
{
    private:
        PhongKS *p;
        int n;
    public:
        List();
        ~List();
        const int& Getlength();
        PhongKS operator[](const int&);   // Nhap: v[i]=v.operator[](i);

        void Show();

        void AddFirst(const PhongKS &);
        void AddLast(const PhongKS &);
        void Insert(const PhongKS &, int);  // vi tri bat ki k

        void Update(string);  // vi tri bat ki k

        void DeleteFirst();
        void DeleteLast();
        void Delete(int); // vi tri k bat ki

        void Merge(int, int, int , bool);
        void MergeSort1(int , int);// Sắp xếp theo giá phòng: sử dụng con trỏ hàm để sắp xếp tăng dần hoặc giảm dần
        void MergeSort2(int , int); // Giảm dần

        int InterpolationSearch(double);
        void Search(double ); // Sử dụng thuật toán tìm kiếm interpolation search
                            // Tìm kiếm theo giá phòng
        
};