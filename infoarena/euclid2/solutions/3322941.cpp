#include <iostream>
using namespace std;
int main()
{
    int n, x, y, i, a, b, r;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x >> y;
        while(y != 0)
        {
            r = x % y;
            x = y;
            y = r;
        }
        cout << x << endl;
    }
}
