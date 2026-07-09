#include <bits/stdc++.h>

using namespace std;



int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    else
        return cmmdc(b, a%b);
}

int t, a, b;

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);

    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a, b)<<endl;
    }

    return 0;
}
