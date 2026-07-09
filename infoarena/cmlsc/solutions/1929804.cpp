#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],LCS[1025][1025];
int n,m,i,j,v[1025],nr;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            LCS[i][j]=1+LCS[i-1][j-1];
        else
        LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
    }
    fout<<LCS[n][m];
    fout<<endl;
    i=n;
    j=m;
    while(i>1||j>1)
    {
         while(j>1 && LCS[i][j]==LCS[i][j-1])
            j--;
          while(i>1 && LCS[i][j]==LCS[i-1][j])
            i--;
          v[++nr]=a[i];
          i--;
          j--;
          if(LCS[i][j] == 0) break;
    }
    for(i=nr;i>=1;i--)
        fout<<v[i]<<' ';
    return 0;
}
