#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("cmlcs.in");
ofstream fout("cmlcs.out");
int s1[1025],s2[1025],s[1025];
int mat[1025][1025];
int main()
{
 int i,j,n,m,x;
 fin>>n>>m;
 for(i=1;i<=n;i++)fin>>s1[i];
 for(i=1;i<=m;i++)fin>>s2[i];
 for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
     {
       if(s1[i]==s2[j]) mat[i][j]=mat[i-1][j-1]+1;
       else  mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
     }
 fout<<mat[n][m]<<'\n';
 i=n;j=m; x=mat[n][m];
 while(i&&j)
     {
      if(s1[i]==s2[j]) s[x--]=s1[i--],j--;
      else if(mat[i-1][j]<mat[i][j-1]) j--;
      else i--;
     }
 for(i=1;i<=mat[n][m];i++) fout<<s[i]<<" ";
 return 0;
}
