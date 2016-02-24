#include <iostream>
using namespace std;

int sn = 1;

class numbered{
public:
    numbered()
    {
        mysn = sn;
        sn++;
    }
    int mysn;
};

void f(numbered s)
{
    cout << s.mysn << endl;
}

int main(void)
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
