#include <iostream>
#include <cstdio>
using namespace std;
int n,a,b;
int euclid(int a, int b)
{
    if (!b)
        return a;
    return euclid(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    cin>>n;
    for (; n; --n)
    {
        cin>>a>>b;
        cout<<euclid(a,b)<<"\n";
    }
    return 0;
}
