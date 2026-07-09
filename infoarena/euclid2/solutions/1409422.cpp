#include <cstdio>
#include <iostream>
using namespace std;
inline int gcd(int a,int b)
{
    int r;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    cin.sync_with_stdio(false);
    int t,a ,b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        cout<<gcd(a,b)<<"\n";
    }
    return 0;
}
