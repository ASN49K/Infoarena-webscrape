#include <iostream>

using namespace std;

int T, x, y;

int gcd(int a, int b)
{
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>x>>y;
        cout<<gcd(x, y)<<"\n";
    }
    return 0;
}
