#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class HasPtr{
    friend ostream &operator<<(ostream &os, const HasPtr &rhs);
public:
    HasPtr(const string &s = string()) :
        ps(new string(s)), i(0)
    {
        cout << "constructor\n";
    }
    HasPtr(const HasPtr &rhs)
    {
        cout << "copy constructor\n";
        ps = new string();
        *ps = *rhs.ps;
        i = rhs.i;
    }
    HasPtr &operator=(const HasPtr &rhs)
    {
        cout << "copy assignment operator\n";
        ps = new string();
        *ps = *rhs.ps;
        i = rhs.i;
        return *this;
    }
    ~HasPtr()
    {
        cout << "destructor\n";
        if (ps) {
            delete ps;
        }
    }
    void swap(HasPtr &lhs, HasPtr &rhs)
    {
        using std::swap;
        swap(lhs.ps, rhs.ps);
        swap(lhs.i, rhs.i);
    }
private:
    string *ps;
    int i;
};
ostream &operator<<(ostream &os, const HasPtr &rhs)
{
    os << *rhs.ps << " " << rhs.i << endl;
    return os;
}

int main(void)
{
    HasPtr p1("hello");
    HasPtr p2("world");
    swap(p1, p2);

    cout << p1;
    cout << p2;

    return 0;
}
