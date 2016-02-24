#include <iostream>
#include <string>
using namespace std;

class Sales_data {
    friend ostream &operator<<(ostream &os, const Sales_data &rhs);
    friend istream &operator>>(istream &is, Sales_data &rhs);
public:
    Sales_data()
    {
        bookNo = "";
        units_sold = 0;
        revenue = 0.0;
    }
    Sales_data(const string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data &operator+(const Sales_data &rhs)
    {
        if (bookNo != rhs.bookNo) {
            return *this;
        }
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
    Sales_data &operator+=(const Sales_data &rhs)
    {
        if (bookNo != rhs.bookNo) {
            return *this;
        }
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
private:
    string bookNo;
    unsigned units_sold;
    double revenue;
};
ostream &operator<<(ostream &os, const Sales_data &rhs)
{
    os << "bookNo:" << rhs.bookNo << "\tunits_sold:" << rhs.units_sold << "\trevenue:" << rhs.revenue << endl;
    return os;
}
istream &operator>>(istream &is, Sales_data &rhs)
{
    double p = 0;
    is >> rhs.bookNo >> rhs.units_sold >> p;
    rhs.revenue = rhs.units_sold * p;
}

int main(void)
{
    Sales_data item1;
    Sales_data item2;
    cin >> item1;
    cin >> item2;
    item1 += item2;
    cout << item1;

    return 0;
}
