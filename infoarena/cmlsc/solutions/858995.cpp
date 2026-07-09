//l[i][j]=lg celui mai lung subsir format din primele i elem din a si primele j elem din b
//https://infoarena.ro/problema/cmlsc
#include <iostream>
#include <cstdio>
using namespace std;

int a[1024],b[1024],m,n,matr[1024][1024],nr,sir[1024];

int maxim(int a,int b)
    {
        if(a>b)
            return a;
          else
            return b;
    }

void citire()
    {
        scanf("%d%d",&m,&n);
        for(int i=1;i<=m;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
    }

int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
citire();
for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
        if(a[i]==b[j])
            matr[i][j]=1+matr[i-1][j-1];
          else
            matr[i][j]=maxim(matr[i][j-1],matr[i-1][j]);
printf("%d\n",matr[m][n]);
for(int i=m,j=n;i,j;)
    {
        if(a[i]==b[j])
            sir[++nr]=a[i],i--,j--;
          else
            if(matr[i-1][j]<matr[i][j-1])
                j--;
              else
                i--;
    }
for(int i=nr;i>0;i--)
    printf("%d ",sir[i]);
    return 0;
}
