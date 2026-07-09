#include <bits/stdc++.h>

using namespace std;

int t;

int gcd(int a,int b)
{
    if(!b)return a;
    else
        return gcd(b,a%b);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    cin>>t;

    int a,b;
    while(t--)
    {
        cin>>a>>b;
        cout<<gcd(a,b)<<'\n';
    }

}
