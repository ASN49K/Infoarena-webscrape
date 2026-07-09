#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int a, b, n,i,c;
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>a>>b;
        while (b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        cout<<a<<endl;
    }
    return 0;
}
