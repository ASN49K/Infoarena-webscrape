#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int x, int y)
{
    if (x%y==0) return y;
    if (y%x==0) return x;
    if (x==2 || y==2)
        if (x%2==1 || y%2==1) return 1;

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
