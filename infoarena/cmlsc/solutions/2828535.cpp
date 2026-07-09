#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,a[1025],b[1025],v[1025][1025],mx,st[1025],k;
int main()
{
    fin>>n>>m;
    for (i=1;i<=n;i++)
        fin>>a[i];
    for (i=1;i<=m;i++)
        fin>>b[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        if (a[i]==b[j]) v[i][j]=1+v[i-1][j-1];
        else v[i][j]=max(v[i-1][j],v[i][j-1]);
    }
        mx=v[n][m];
        i=n;
        j=m;
        fout<<mx<<'\n';
        while (mx)
        {
            if (a[i]==b[j])
            {

            st[++k]=a[i];
            mx--;
            i--;
            j--;
            }
            else if (mx==v[i-1][j]) i--;
            else j--;
        }


    for (i=k;i>=1;i--)
    {
        fout<<st[i]<<" ";
    }
    return 0;
}
