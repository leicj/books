#include <iostream>
#include <string>
using namespace std;

class HasPtr{
    friend ostream &operator<<(ostream &os, const HasPtr &rhs);
public:
    HasPtr(const string &s = string()) :
        ps(new string(s)), i(0), use(new size_t(1)){}
    HasPtr(const HasPtr &p) :
        ps(p.ps), i(p.i), use(p.use) {++*use;}
    HasPtr &operator=(const HasPtr &);
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr::~HasPtr()
{
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    use = rhs.use;
    i = rhs.i;
    return *this;
}
ostream &operator<<(ostream &os, const HasPtr &rhs)
{
    os << *rhs.ps << endl;
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
