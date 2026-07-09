#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,l,a[1025],b[1025],d[1025][1025],sir[1025];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>a[i];
    for(i=1;i<=m;i++) fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    i=n;j=m;
    while(i)
        if(a[i]==b[j])
    {
        sir[++l]=a[i];
        i--; j--;
    }
    else if(d[i-1][j]<d[i][j-1]) j--;
    else i--;
    fout<<l<<"\n";
    for(i=l;i>=1;i--) fout<<sir[i]<<" ";
    return 0;
}
