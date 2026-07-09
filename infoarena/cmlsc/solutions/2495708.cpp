#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1026],b[1026],v[1026][1026],n,m,i,j,d[1026];
int main()
{
    fin>>n>>m;
    v[0][0]=0;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
        v[i][0]=0;
    }
    for(i=1;i<=m;i++)
    {
        fin>>b[i];
        v[0][i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    i=n;
    j=m;
    int k=0;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            k++;
            d[k]=a[i];
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
            {
                j--;
            }
        }
    }
    fout<<v[n][m]<<"\n";
    for(i=k;i>=1;i--)
    {
        fout<<d[i]<<" ";
    }
    fin.close();
    fout.close();
    return 0;

}
