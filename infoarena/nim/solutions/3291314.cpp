#include <bits/stdc++.h>
#define nmx 500005
#define inf 2000000000
using namespace std;
int t,n,s,x;
int main()
{
    ifstream f ("nim.in");
    ofstream g ("nim.out");
    f>>t;
    while (t--)
    {
        f>>n;
        s=0;
        for (int i=1;i<=n;i++)
        {
            f>>x;
            s^=x;
        }
        if (s==0)
            g<<"NU"<<'\n';
        else g<<"DA"<<'\n';
    }
}
