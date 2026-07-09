#include <iostream>
#include <fstream>
using namespace std;
int n,m,a[1025],b[1025],v[1025],nr,i,j;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(j=1;j<=m;j++)
        in>>b[j];
    nr=1;
    for(i=1;i<=n;i++)
    {
        for(j=nr;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                v[nr]=a[i];
                nr++;
                j=m+1;
            }
        }
    }
    out<<nr-1<<endl;
    for(i=1;i<=nr-1;i++)
        out<<v[i]<<" ";
}
