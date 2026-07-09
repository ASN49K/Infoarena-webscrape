#include <bits/stdc++.h>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
typedef long long ll;
ll tst,n,s,x;
int main()
{
    in>>tst;
    while(tst--)
    {
        in>>n; s=0;
        for(ll i=1;i<=n;++i)
            in>>x,s^=x;
        if(s) out<<"DA" "\n";
        else out<<"NU" "\n";
    }
    return 0;
}
