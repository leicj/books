#include <iostream>
using namespace std;

int sn = 1;

class numbered{
public:
    numbered()
    {
        cout << "constructor\n";
        mysn = sn;
        sn++;
    }
    numbered(const numbered &rhs)
    {
        cout << "copy constructor\n";
        mysn = sn;
        sn++;
    }
    int mysn;
};

void f(const numbered &s)
{
    cout << s.mysn << endl;
}

int main(void)
{
    numbered a, b = a, c = b;
    cout << "f(a)" << endl;
    f(a);
    cout << "f(b)" << endl;
    f(b);
    cout << "f(c)" << endl;
    f(c);

    return 0;
}
