#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int a,b;
    for (int i=1; i<=n; i++)
    {
        cin>>a>>b;
        cout<<__gcd(a,b)<<'\n';
    }
    return 0;
}
