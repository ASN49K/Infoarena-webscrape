#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int n,int m)
{
    int r;
    while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}
int main()
{
    int t,v[100001],x[100001];
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>v[i]>>x[i];
        g<<euclid(v[i],x[i]);
        g<<endl;
    }
    return 0;
}
