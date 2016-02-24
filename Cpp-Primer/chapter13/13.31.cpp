#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class HasPtr{
    friend ostream &operator<<(ostream &os, const HasPtr &rhs);
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
public:
    HasPtr(const string &s = string()) :
        ps(new string(s)), i(0)
    {
    }
    HasPtr(const HasPtr &rhs)
    {
        ps = new string();
        *ps = *rhs.ps;
        i = rhs.i;
    }
    HasPtr &operator=(const HasPtr &rhs)
    {
        ps = new string();
        *ps = *rhs.ps;
        i = rhs.i;
        return *this;
    }
    ~HasPtr()
    {
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
    os << *rhs.ps;
    return os;
}
bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return (*lhs.ps).size() <= (*rhs.ps).size();
}

int main(void)
{
    HasPtr p1("aaaaa");
    HasPtr p2("bbbb");
    HasPtr p3("ccc");
    HasPtr p4("dd");
    HasPtr p5("e");
    vector<HasPtr> hvec;
    hvec.push_back(p2);
    hvec.push_back(p4);
    hvec.push_back(p3);
    hvec.push_back(p1);
    hvec.push_back(p5);
    sort(hvec.begin(), hvec.end());

    for (int i = 0; i < hvec.size(); i++) {
        cout << hvec[i] << " ";
    }
    cout << endl;

    return 0;
}
