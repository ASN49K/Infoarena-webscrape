#include <iostream>
#include <fstream>

using namespace std;
int n,m;
int a[1025],b[1025];
int mat[1025][1025];
int s[1025];
int maxx(int a,int b,int c)
{
    return max(a,max(b,c));
}
void citire()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d ",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
}
void lmax()
{int v;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        v=a[j]==b[i];
        mat[i][j]=maxx(mat[i-1][j],mat[i][j-1],mat[i-1][j-1]+v);
    }
    printf("%d\n",mat[m][n]);
}
void drum()
{int i=m,j=n,v;
  while(i && j)
  {
      v=a[j]==b[i];
      if(v==1)
      s[mat[i][j]]=a[j],i--,j--;
      else if(mat[i-1][j]>mat[i][j-1])
               i--;
           else j--;
  }
  for(int i=1;i<=mat[m][n];i++)
    printf("%d ",s[i]);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    lmax();
    drum();
    return 0;
}
