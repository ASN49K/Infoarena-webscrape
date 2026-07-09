#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,k,nr,v1[100],v2[100],v3[100];
int main()
{

    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v1[i];
    for(i=1;i<=m;i++)
        f>>v2[i];
        k=0;
    for(i=1;i<=n;i++)
    {
        for(j=k+1;j<=m;j++)
            if(v1[i]==v2[j])nr++,v3[nr]=v2[j],k=j;
    }
    g<<nr<<endl;
    for(i=1;i<=nr;i++)
        g<<v3[i]<<" ";
    g<<endl;
 f.close();
 g.close();
    return 0;
}
