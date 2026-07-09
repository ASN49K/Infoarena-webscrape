#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,p,a[1025],b[1025],mat[1025][1025],x[100001],bb;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>a[i];
    for(i=1;i<=m;i++)fin>>b[i];

    for(i=1;i<=n;i++)
    for(p=1;p<=m;p++)
    {
                if(a[i]==b[p]){mat[i][p]=mat[i-1][p-1]+1;}
                else mat[i][p]=max(mat[i-1][p],mat[i][p-1]);
    }
    for(i=n,p=m;i>0;)
    {
            if(a[i]==b[p])
        {
            x[++bb]=a[i];
            i--;
            p--;
        }
            else
            if (mat[i-1][p]<mat[i][p-1])
                p--;
            else
                i--;
    }
      fout<<mat[n][m]<<'\n';
    for(i=bb;i>0;i--)
        fout<<x[i]<<' ';
    return 0;
}
