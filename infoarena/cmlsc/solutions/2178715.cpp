#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int c[1000][1000];
int main()
{
    int n,m,a[1000],b[1000],d[678];
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            c[i][j]=max(c[i-1][j],c[i][j-1])+1;
        else
        {
            c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    }
    int k=0;
    int i=n;
    int j=m;
while(c[i][j])
{
    if(a[i]==b[j])
    {
         d[k++]=a[i];
        i--;
        j--;

    }
    if(c[i-1][j]==c[i][j])
    i--;
    else
        j--;

}
cout<<c[n][m]<<endl;
        for(int p=k-1;p>=0;p--)
            cout<<d[p]<<" ";

    return 0;
}
