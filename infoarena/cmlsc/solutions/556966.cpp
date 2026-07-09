#include <iostream>
#include<stdio.h>
#define dim 1025


using namespace std;

int a[dim],b[dim],v[dim][dim];
int n,m;

void read()
{
    scanf("%d %d\n",&n,&m);
    for(int i=1 ; i<=n;i++)
     {
         scanf("%d",&a[i]);
      //   printf("%d ",a[i] ) ;
     }
    for(int k=1 ; k<=m;k++)
        scanf("%d",&b[k]);
}
int max ( int x , int y )
{
  //  return !x?:y;
  if ( x>y)
  return x;
  return y;

}
void dinamica ()
{
    for(int i=1 ; i<=n;i++)
        for(int k=1 ; k<=m;k++)
        {
            if ( a[i] == b[k] )
            {
                v[i][k] = v[i-1][k-1]+1;
            }
            else
                v[i][k] = max ( v[i-1][k], v[i][k-1] );
            }

}
void afis ()
{
    for(int i=1 ; i<=n;i++,printf("\n"))
    for(int k=1 ; k<=m;k++)
    printf("%d ",v[i][k] ) ;
}
void find_sol()
{
    int sol[dim],poz=0;
    for(int i=n ,k=m ; k>=1 && i>=1 ; )
    {
        if ( a[i] == b[k] )
        {
            sol[++poz]=a[i] ;
            i--,k--;
            continue;
        }
          if ( v[i][k-1]<v[i-1][k])
                i--;
            else
                k--;
    }
printf("%d\n",poz);
    for(int i=poz ; i>=1; i--)
    printf("%d ",sol[i]);
}
int main()
{
   freopen("cmlsc.in","r",stdin);
   freopen("cmlsc.out","w",stdout);
    read() ;
    dinamica();
   // afis ();
  // printf("%d\n",v[n][m]);
    find_sol () ;
  return 0;
}
