#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int n,m,maxim=0,poz=0;
    int a[1000],b[1000],s[1000];
    f>>n>>m;
    for(int i=0;i<n;i++)
        f>>a[i];
    for(int i=0;i<m;i++)
        f>>b[i];
    for(int i=0;i<n;i++)
    {
        for(int j=poz;j<m;j++)
        {
            if(a[i]==b[j])
            {
                s[maxim]=a[i];
                poz=j;
                maxim++;
                break;
            }
        }
    }
    g<<maxim<<"\n";
    for(int i=0;i<maxim;i++)
        g<<s[i]<<" ";
    f.close();g.close();
}
