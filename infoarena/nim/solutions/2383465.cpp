#include<bits/stdc++.h>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t,x,n;
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>n;
        x=0;
        for(int j=1;j<=n;++j)
        {
            int y;
            f>>y;
            x^=y;
        }
        if(x)
            g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }

    return 0;
}
