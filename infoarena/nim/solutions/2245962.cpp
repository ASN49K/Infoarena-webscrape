#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    int t,i,j,n,x,OK=0;
    f>>t;
    for (i=1;i<=t;i++)
    {
        OK=0;
        f>>n;
        for (j=1;j<=n;j++)
        {
            f>>x;
            if (j==1&&x!=1)
                OK=1;
        }
        if (OK) g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }
}
