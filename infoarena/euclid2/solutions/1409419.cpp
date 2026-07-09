#include <cstdio>
#include <iostream>
using namespace std;
inline int gcd(const int a,const int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
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
