#include <bits/stdc++.h>
using namespace std;
int t,n,i,s,x;
int main()
{
    ifstream f ("nim.in");
    ofstream g ("nim.out");
    f>>t;
    ++t;
    while(--t)
    {
        f>>n;
        s=0;
        for(i=1; i<=n; ++i)
        {
            f>>x;
            s^=x;
        }
        if(s)g<<"DA"<<'\n';
        else g<<"NU"<<'\n';
    }
    return 0;
}
