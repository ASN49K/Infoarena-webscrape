#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1030],b[1030],v[1030][1030],rez[1030],cnt=0;

void cmlsc(int a[], int n, int b[], int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i][j-1],v[i-1][j]);
        }
    }
    fout<<v[n][m]<<"\n";
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(a[i]==b[j])
            {
                 rez[++cnt]=a[i];
                 i--;
                 j--;
            }
            else if(v[i][j-1]<v[i-1][j])
                i--;
            else j--;

        }
    }
    for(int i=cnt;i>=1;i--)
        fout<<rez[i]<<" ";
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    cmlsc(a,n,b,m);
    return 0;
}
