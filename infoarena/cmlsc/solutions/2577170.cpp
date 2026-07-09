#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024],b[1024],c[1024],d[1024][1024],n,m,i,j,k,nr;
int main()
{
    fin >> n >> m;
    for (i=1;i<=n;i++)
        fin >> a[i];
    for (i=1;i<=m;i++)
        fin >> b[i];
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    fout << d[n][m] << "\n";
    nr=d[n][m];
    for(i=n;i>=1;i--)
    {
        for(j=m;j>=1;j--)
        {
            if(a[i]==b[j] && d[i][j]==nr)
            {
                k++;
                c[k]=a[i];
                nr--;
            }
        }
    }
    for (i=d[n][m];i>=1;i--)
    {
        fout << c[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
