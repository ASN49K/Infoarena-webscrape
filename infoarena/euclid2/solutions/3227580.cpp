#include <iostream>
using namespace std;
int a, b, r, t;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        cout << a << "\n";
    }
    return 0;
}
