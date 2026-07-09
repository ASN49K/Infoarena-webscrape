#include <cstdio>

using namespace std;
int v1[1025];
int v2[1025];
int mat[1025][1025];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int m,n,i,j,max,cnt;
    max=0;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        scanf("%d",&v1[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&v2[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(v1[j]==v2[i]){
            mat[i][j]=mat[i-1][j-1]+1;
            if(mat[i][j]>max)
                max=mat[i][j];
        }
        else
            mat[i][j]=max;
    }
    printf("%d\n",max);
    cnt=max;
    max=0;
    for(i=1;i<=n && cnt>0;i++)
        for(j=1;j<=m && cnt>0;j++)
    {
        if(mat[i][j]>max)
          {
              max=mat[i][j];
              printf("%d ",v2[i]);
              cnt--;
          }
    }
    return 0;
}
