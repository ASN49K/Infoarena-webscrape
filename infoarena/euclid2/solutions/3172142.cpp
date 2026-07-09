#include <iostream>

using namespace std;

int a, b, rest;

int main()
{
    cin >> a >> b;
    while(b)
    {
        rest = a % b;
        a = b;
        b = rest;

    }
    cout << a;
    return 0;
}
