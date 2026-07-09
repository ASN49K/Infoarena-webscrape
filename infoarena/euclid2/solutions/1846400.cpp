#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int v[200001],i,r,n;
    f>>n;
    for(i=1;i<=n*2;i++)
        f>>v[i];
    for(i=1;i<=n*2;i=i+2)
    {
        r=v[i]%v[i+1];
        while(r)
        {
         v[i]=v[i+1];
         v[i+1]=r;
         r=v[i]%v[i+1];
        }
        g<<v[i+1]<<endl;
    }
    return 0;
}
