#include <iostream>
#include <fstream>
using namespace std;
ifstream f("combinari.in");
ofstream g("combinari.out");
int v[19],n,k;
void bk(int s)
{
    for(int i=v[s-1]+1;i<=n;i++)
    {
        v[s]=i;
        if(s==k)
        {
            for(int j=1;j<=k;j++)
            {
                g<<v[j]<<" ";
            }
            g<<"\n";
        }
        else
        {
            bk(s+1);
        }
    }
}
int main()
{
    f>>n>>k;
    bk(1);
    return 0;
}
