#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int m)
{
   if(m==0)
    return a;
   else
    return gcd(m,a%m);
}
int main()
{
    int n,m,a;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>m>>a;
        cout<<gcd(a,m)<<'\n';
    }
    return 0;
}
