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
    Employee(const Employee &);
    Employee &operator=(const Employee &);
private:
    string _name;
    int _sn;
    static int _static_sn;
};
int Employee::_static_sn = 1;
Employee::Employee(const Employee &rhs)
{
    _name = rhs._name;
    _sn = rhs._static_sn;
    rhs._static_sn++;
}
Employee &Employee::operator=(const Employee &rhs)
{
    _name = rhs._name;
    _sn = rhs._static_sn;
    rhs._static_sn++;
    return *this;
}
ostream &operator<<(ostream &os, const Employee &em)
{
    os << "name:" << em._name << "; sn:" << em._sn << endl;
    return os;
}

int main(void)
{
    Employee em1("leicj");
    Employee em2(em1);
    Employee em3 = em1;

    cout << em1;
    cout << em2;
    cout << em3;

    return 0;
}
