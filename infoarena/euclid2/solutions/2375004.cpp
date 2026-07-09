#include <fstream>
#include <iostream>
using namespace std;


int a, b, n, r;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a >> b;
        if (a < b)
        {
            r = a;
            a = b;
            b = r;
        }
        while (b!=0)
        {
            r = a%b;
            a = b;
            b = r;
        }
        cout << a << '\n';
    }
}
