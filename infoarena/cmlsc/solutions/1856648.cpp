#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],mat[1025][1025],fin[1025],lg,i,j;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
      f>>a[i];
    for(i=1;i<=m;i++)
      f>>b[i];
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        if(a[i]==b[j])
          mat[i][j]=mat[i-1][j-1]+1;
        else
          mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    i=n;
    j=m;
    while(i>=1&&j>=1)
    {
        int val=mat[i][j];
        while(mat[i-1][j]==val)
          i--;
        while(mat[i][j-1]==val)
          j--;
        lg++;
        fin[lg]=a[i];
        i--;
        j--;
    }
    lg=mat[n][m];
    g<<lg<<"\n";
    for(i=lg;i>=1;i--)
      g<<fin[i]<<" ";
    return 0;
}
