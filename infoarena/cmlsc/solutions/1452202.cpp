#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int a[101],b[101],i,j,n,m;
void Citire()
{
    freopen("date.in", "r", stdin);
    freopen("date.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(i=1;i<=n;++i)
        scanf("%d", &a[i]);
    for(i=1;i<=m;++i)
        scanf("%d", &b[i]);
}
#define maxim(a, b) ((a > b) ? a : b)
int dist[101][101];
void ConstruireMatrice()
{
    for(i=1;i<=n;++i)
      for(j=1;j<=m;++j)
        if(a[i]==b[j])
            dist[i][j]=dist[i-1][j-1]+1;
        else
            dist[i][j]=maxim(dist[i][j-1],dist[i-1][j]);

}
void AfisareSol()
{   int k=0,sol[101];
    i=n,j=m;
    while(i>=0 && j>=0)
       {
           if(a[i]==b[j])
               sol[++k]=a[i],--i,--j;
           else
              if(dist[i-1][j]<dist[i][j-1])
                     --j;
              else
                     --i;
       }
     printf("%d \n",k);
     for(i=k;i>=1;i--)
        printf("%d ",sol[i]);
}
int main()
{
   Citire();
   ConstruireMatrice();
   AfisareSol();
   return 0;
}
