#include <iostream>
#include <fstream>
using namespace std;
int n,m,a[1025],b[1025],v[1025],nr,x,i,j;
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
    x=0;
    for(i=1;i<=n;i++)
    {
        for(j=nr;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                v[nr]=a[i];
                nr=nr+j;
                j=m+1;
                x++;
            }
        }
    }
    out<<x<<endl;
    for(i=1;i<=x;i++)
        out<<v[i]<<" ";
}
