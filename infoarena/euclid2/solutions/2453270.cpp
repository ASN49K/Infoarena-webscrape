#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int x, int y)
{
    while (x!=y)
    {
        if (x>y) x-=y;
        if (x<y) y-=x;
    }
    return x;
}

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n,a,b;
    cin>>n;
    int v[n+1];
    for (int i=1; i<=n; i++)
    {
        cin>>a>>b;
        v[i]=cmmdc(a,b);
    }
    for (int i=1; i<=n; i++) cout<<v[i]<<'\n';
    return 0;
}
