#include <iostream>

using namespace std;

int cmmdc(int a, int b)
{
    if(b == 0) return a;
    return cmmdc(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << cmmdc(a, b) << "\n";
    }
}
