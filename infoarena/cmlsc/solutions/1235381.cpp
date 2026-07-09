#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int ma[260][260],n,m,v[260],p=0;
short int a[1025],b[1025];
int main()
{
    in>>m>>n;
    for(int i=1;i<=m;i++)
        in>>a[i];
    for(int i=1;i<=n;i++)
        in>>b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i]!=b[j])
                ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
            else if(a[i]==b[j])
                ma[i][j]=ma[i-1][j-1]+1;

        out<<ma[i][j];
    return 0;
}
