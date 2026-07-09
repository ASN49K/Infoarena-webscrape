#include<iostream>
#include<fstream>
#include<cstring>
#define MAX 257
using namespace std;
fstream fin("cmlsc.in",ios::in),fout("cmlsc.out",ios::out);
unsigned char a[MAX],b[MAX],x[MAX][MAX],v[MAX];
int main()
{
    int n,m,i,j,k=0;
    fin>>n>>m;
    for(i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(j=1; j<=m; j++)
    {
        fin>>b[j];
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                x[i][j]=x[i-1][j-1]+1;
            }
            else
            {
                x[i][j]=max(x[i][j-1],x[i-1][j]);
            }
        }
    }
    fout<<(int)x[n][m]<<'\n';
    i=n;
    j=m;
    while(i>0 && j>0 && x[i][j]>0)
    {
        if(a[i]==b[j])
        {
            v[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(x[i-1][j]>x[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(i=k;i>=1;i--)
    {
        fout<<v[i]<<" ";
    }
fin.close();
fout.close();
return 0;
}
