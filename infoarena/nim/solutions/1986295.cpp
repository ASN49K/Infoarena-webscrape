#include <bits/stdc++.h>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int main()
{
    int t,n,i,j,x,s;
    f>>t;
    for(j=1;j<=t;j++)
    {
        f>>n;
        s=0;
        for(i=1;i<=n;i++)
        {
            f>>x;
            s^=x;
        }
        if(s>0) g<<"DA";
        else g<<"NU";
        g<<'\n';
    }

    return 0;
}
