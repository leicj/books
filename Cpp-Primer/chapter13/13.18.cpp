#include <iostream>
#include <string>
using namespace std;

class Employee{
    friend ostream &operator<<(ostream &, const Employee &);
public:
    Employee(const string &name) :
        _name(name)
    {
        _sn = _static_sn;
        _static_sn++;
    }
private:
    string _name;
    int _sn;
    static int _static_sn;
};
int Employee::_static_sn = 1;
ostream &operator<<(ostream &os, const Employee &em)
{
    os << "name:" << em._name << "; sn:" << em._sn << endl;
    return os;
}

int main(void)
{
    Employee em1("leicj");
    Employee em2("ligt");

    cout << em1;
    cout << em2;

    return 0;
}
