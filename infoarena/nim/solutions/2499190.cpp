#include <bits/stdc++.h>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,x,rez;
int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>n;
        rez=0;
        for(;n;n--)
        {
            f>>x;
            rez^=x;
        }
        rez?g<<"DA\n":g<<"NU\n";
    }

    return 0;
}
