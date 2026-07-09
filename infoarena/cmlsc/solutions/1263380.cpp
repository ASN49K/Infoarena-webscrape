#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
#define nmax 1024
int ma[nmax][nmax],n,m,v[nmax],p=0,a[nmax],b[nmax];
int main()
{
    int i,j;
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>a[i];
    for(i=1;i<=n;i++)
        in>>b[i];
    in.close();
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]!=b[j])
                ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
            else
                ma[i][j]=ma[i-1][j-1]+1;
    for(i=m;i>0;)
        for(j=n;j>0;)
            if(a[i]==b[j])
            {
                v[++p]=a[i];
                i--;
                j--;
            }
            else if(ma[i-1][j]<ma[i][j-1])
                j--;
            else i--;
    out<<p<<"\n";
    for(p;p>0;p--)
        out<<v[p]<<" ";
    out.close();
    return 0;
}
