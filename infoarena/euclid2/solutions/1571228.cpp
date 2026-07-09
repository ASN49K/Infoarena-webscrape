#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,i,v[100],t[100],r=1,a,b;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
        f>>t[i];
    }
    for(i=1;i<=n;i++)
    {
        a=v[i];
        b=t[i];
        r=1;
    while(r!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<endl;
    }
    return 0;
}
