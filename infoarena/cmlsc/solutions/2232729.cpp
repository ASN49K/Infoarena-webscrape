#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025][1025],sol[1025];
int main()
{
        int n,m,nr=0,v[1025],u[1025];
        f>>n>>m;
        for(int i=1;i<=n;++i)
            f>>v[i];
        for(int j=1;j<=m;++j)
            f>>u[j];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
              if(v[i]==u[j])
                 {
                     a[i][j]=a[i-1][j-1]+1;
                 }
              else a[i][j]=max(a[i-1][j],a[i][j-1]);
        int i=n,j=m;
        while(i and j)
            if(v[i]==u[j])
               sol[++nr]=v[i],i--,j--;
            else if(a[i-1][j]>a[i][j-1])
                    i--;
                 else j--;
        g<<a[n][m]<<endl;
        for(int i=1;i<=nr;++i)
            g<<sol[i]<<' ';
    return 0;
}
