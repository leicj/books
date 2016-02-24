#include <iostream>
#include <string>
using namespace std;

class HasPtr{
public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0){}
    HasPtr(const HasPtr &rhs)
    {
        ps = new string(*rhs.ps);
        i = rhs.i;
        cout << "copy constructor\n";
    }
    HasPtr &operator=(const HasPtr& rhs)
    {
        ps = new string(*rhs.ps);
        i = rhs.i;
        cout << "copy assignment operator\n";
    }
    void show()
    {
        cout << *ps << " " << i << endl;
    }
private:
    string *ps;
    int i;
};

int main(void)
{
    HasPtr p1("hello");
    HasPtr p2;
    p2 = p1;
    p2.show();

    return 0;
}
