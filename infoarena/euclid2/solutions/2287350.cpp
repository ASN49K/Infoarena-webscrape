#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;

inline int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int kol1,kol2;
        cin>>kol1>>kol2;
        cout<<gcd(kol1,kol2)<<"\n";
    }
    return 0;
}
