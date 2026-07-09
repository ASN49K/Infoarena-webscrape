#include <bits/stdc++.h>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
const int lim=1e4+5;
int v[lim];
int main()
{
    int tst,n,sum;
    in>>tst;
    while(tst--)
    {
        in>>n;
        for(int i=1;i<=n;++i)
            in>>v[i];
        sum=v[1];
        for(int i=2;i<=n;++i)
            sum=(sum^v[i]);
        if(sum==0)
            out<<"NU"<<'\n';
        else out<<"DA"<<'\n';
    }
    return 0;
}
