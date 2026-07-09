#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,v[1030][1030],a[1030],b[1030],sol[1030],k=0;
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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    fout<<v[n][m];
    int i=n,j=m;
    while(i && j && v[i][j])
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(v[i-1][j]>v[i][j-1])
            {
                i--;
            }
            else
                j--;
        }
    }
    fout<<"\n";
    for(int i=k;i>=1;i--)
        fout<<sol[i]<<" ";
    return 0;
}
