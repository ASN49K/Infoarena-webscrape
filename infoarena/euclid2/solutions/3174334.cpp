#include <iostream>

using namespace std;

int gcd(int a, int b)
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
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int a, b;
        cin>>a>>b;
        cout<<gcd(a, b)<<'\n';
    }
    return 0;
}
