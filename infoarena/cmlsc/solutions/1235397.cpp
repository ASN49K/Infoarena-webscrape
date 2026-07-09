#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int ma[260][260],n,m,v[260],p=0;
short int a[1025],b[1025];
int main()
{
    int i,j;
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>a[i];
    for(i=1;i<=n;i++)
        in>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]!=b[j])
                ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
            else if(a[i]==b[j])
                ma[i][j]=ma[i-1][j-1]+1;
    out<<ma[m][n];
    return 0;
}
