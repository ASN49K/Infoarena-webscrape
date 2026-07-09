#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    int t,i,j,n,x,s=0;
    f>>t;
    for (i=1;i<=t;i++)
    {
        s=0;
        f>>n;
        for (j=1;j<=n;j++)
        {
            f>>x;
            s=s^x;
        }
        if (s) g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }
}
