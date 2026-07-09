#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int m,n,a[2000],b[2000],i,j,s=0,sir[2000];
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m;
    f>>n;
    for(i=1;i<=m;i++)
                     f>>a[i];
    for(i=1;i<=n;i++)
                     f>>b[i];
    for(i=1;i<=m;i++)
     for(j=1;j<=n;j++)
                        if(a[i]==b[j])
                        {
                                      s++;
                                      sir[s]=a[i];
                        }
    g<<s<<"\n";
    for(i=1;i<=s;i++)
                     g<<sir[i]<<" ";
    g<<"\n";
    f.close();
    g.close();
    return 0;
}
