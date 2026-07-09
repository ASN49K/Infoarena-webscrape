#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int n,m,a[1030],b[1030],ma[1030][1030];
void afis(int i,int j)
{
    if(ma[i][j]>0)
    {
        while(ma[i-1][j]==ma[i][j])
            i--;
        while(ma[i][j-1]==ma[i][j])
            j--;
        afis(i-1,j-1);
        fout<<a[i]<<" ";
    }

}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int j=1;j<=m;j++)
        fin>>b[j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                ma[i][j]=max(ma[i-1][j],max(ma[i][j-1],ma[i-1][j-1]+1));
            else
                ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
        }
    }
    fout<<ma[n][m]<<'\n';
    afis(n,m);
    return 0;
}
