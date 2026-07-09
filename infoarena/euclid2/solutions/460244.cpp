#include <iostream.h>
#include <stdio.h>
using namespace std;

int T, x, y;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
 
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
 
    cin>>T;
    for (; T; --T)
    {
        cin>>x>>y;
        cout<<gcd(x, y);
    }       
    
    return 0;
}
