#include<cstdio>
#include<algorithm>
using namespace std;
int a[1025],b[1025],v[1025][1025],l[1025];
int main()
{
    freopen("cmlsc.in","r",stdin);freopen("cmlsc.out","w",stdout);

    int x,y,i,j;
    scanf("%d %d",&x,&y);
    for(i=1;i<=x;++i)
        scanf("%d",&a[i]);
    for(i=1;i<=y;++i)
        scanf("%d",&b[i]);

    for(i=1;i<=x;++i)
        for(j=1;j<=y;++j)
            if(a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
              else         v[i][j]=max(v[i-1][j],v[i][j-1]);

    i=x;j=y;
    int n=0;
    while(i>0 && j>0)
    {
        if(a[i]==b[j]) l[++n]=a[i],--i,--j;
         else
          if(v[i-1][j]<v[i][j-1]) --j;
                else              --i;
    }

  printf("%d\n",n);
  for(i=n;i>0;--i)
     printf("%d ",l[i]);

 return 0;
}
