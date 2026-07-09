#include <bits/stdc++.h>
using namespace std;
int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
#ifdef HOME
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif // HOME
#ifndef HOME
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
#endif // HOME
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,a,b;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
