#include <iostream>
#include <string>
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
    HasPtr p2(p1);
    HasPtr p3;
    p3 = p1;

    cout << p1;
    cout << p2;
    cout << p3;

    return 0;
}
