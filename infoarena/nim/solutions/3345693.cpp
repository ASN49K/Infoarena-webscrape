#include <bits/stdc++.h>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
signed main ()
{
    int t;
    f >> t;
    while (t--)
    {
        int n;
        f >> n;
        int ans=0;
        while (n--)
        {
            int x;
            f >> x;
            ans=(ans^x);
        }
        if (ans) g <<"DA\n";
        else g <<"NU\n";
    }
}
