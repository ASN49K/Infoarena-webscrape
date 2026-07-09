#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,i,a[1024],b[1024],j,c[1024],k=1,l,sw=0;
int main()
{
    f>>n>>m;
    for(i=0;i<n;i++)
    {
        f>>a[i];
    }
    for(i=0;i<m;i++)
    {
        f>>b[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            sw=0;
            if(a[i]==b[j])
            {
                for(l=1;l<=k;l++)
                {
                    if(a[i]==c[l]) sw=1;
                }
                if(sw==0) c[k++]=a[i];
            }
        }
    }
    g<<--k<<'\n';
    for(i=1;i<=k;i++)
    {
        g<<c[i]<<' ';
    }
    g<<'\n';
    return 0;
    f.close();
    g.close();
}
