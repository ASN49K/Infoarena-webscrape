#include <stdio.h>

using namespace std;
int m,n,i,j,k,a[1025],b[1025],c[1025][1025],sol[1025];

int max(int x,int y)
{
  if (x>y) return x;
       else return y;
};

void afis(int k,int h)
{
   if(c[k][h])
     if(a[k]==b[h])
       {afis(k-1,h-1);
       printf("%d ",a[k]);}
     else
        {if (c[k][h]==c[k-1][h])
         afis(k-1,h);
         else if (c[k][h]==c[k][h-1])
         afis(k,h-1);
        } ;

};

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&m,&n);
    for (i=1;i<=m;i++)
    {
      scanf("%d",&a[i]);

    };
    for (j=1;j<=n;j++)
    {
      scanf("%d",&b[j]);
      for (i=1;i<=m;i++)
       {
         if (b[j]==a[i]){c[i][j]=c[i-1][j-1]+1;}
                           else {c[i][j]=max(c[i-1][j],c[i][j-1]);};
       };
    };
    printf("%d\n",c[m][n]);
    afis(m,n);
    return 0;
}
