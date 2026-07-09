#include<iostream>
#include<fstream>
using namespace std;
long long i, t, n, s, x;
int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    scanf("%d", &t);
    for(int k = 1; k <= t; k++)
    {
        scanf("%d", &n);
        s = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            s ^= x;
        }
        if(s == 0)
        {
            cout << "NU\n" ;
        }
        else cout << "DA\n" ;
    }
}
