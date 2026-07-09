#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,i,v[100000],t[100000],r=1;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
        f>>t[i];
    }
    for(i=1;i<=n;i++)
    {
        r=1;
    while(r!=0)
    {
        r=v[i]%t[i];
        v[i]=t[i];
        t[i]=r;
    }
    g<<v[i]<<endl;
    }
    return 0;
}
