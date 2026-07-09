#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int din[1026][1026], a[1026], b[1026], n, m, i, j, v[1026], in;

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                din[i][j]=din[i-1][j-1]+1;
            }
            else
            {
                din[i][j]=max(din[i-1][j],din[i][j-1]);
            }
        }
    }
    i=n;
    j=m;
    in=din[i][j];
    fout<<in<<'\n';
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j])
        {
            v[in]=a[i];
            in--;
            i--;
            j--;
        }
        else
        {
            if(din[i-1][j]>din[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=1;i<=din[n][m];i++)
    {
        fout<<v[i]<<" ";
    }
    return 0;
}
