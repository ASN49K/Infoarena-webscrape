#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sircomun.in");
ofstream fout("sircomun.out");
int c[1025][1025],a[1025],b[1025],v[1025],n,m;
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            c[i][j]=c[i-1][j-1]+1;
            else
            if(c[i][j-1]>=c[i-1][j])
                c[i][j]=c[i][j-1];
            else
                c[i][j]=c[i-1][j];
        }

        fout<<c[n][m]<<'\n';

        int i=n,j=m,k=1;

        while((i>=0&&j>=0)&&c[i][j]!=0)
        {
            if(a[i]==b[j])
            {
                v[k]=a[i];
                k++;
                i--;
                j--;
            }
            else if(c[i-1][j]<c[i][j-1]){j--;
            }
            else i--;

        }
        for(int i=k-1;i>=1;i--)
            fout<<v[i]<<" ";
    return 0;
}
