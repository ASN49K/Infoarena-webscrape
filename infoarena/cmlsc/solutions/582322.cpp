#include<stdio.h>

#define dim 1050

int a[dim],b[dim],n,m;
int best[dim][dim];
int sol[dim],poz;
void scanff(int a[dim] , int n)
{
    for(int i=1 ; i<=n; i++)
    scanf("%d",&a[i]);
}
void read()
{
    scanf("%d %d",&n,&m);
    scanff(a,n);
    scanff(b,m);
}
void afis()
{
    for(int i=1 ; i<=n ; i++,printf("\n") )
    for(int k=1 ; k<=m ; k++ )
    printf("%d ",best[i][k]);
}
int max ( int a , int b)
{
    if (a>b )
    return a;
    return b;

}
void solve()
{
    for(int i=1 ; i<=n ; i++)
    {
        for(int k=1 ; k<=m ; k++)
        {
            if ( a[i] == b[k] )
                best[i][k]= best[i-1][k-1]+1;
            else
            best[i][k] =max (  best[i-1][k] , best[i][k-1]);
        }
    }
  //  afis() ;

}
void afis2(int a[dim] ,int n )
{
    printf("%d\n",poz);
    for(int i=n ; i>=1 ; i--)
    printf("%d ",a[i]);
}
void find_sol()
{
    for(int i=n ,k=m; i>=1 , k>=1 ;)
    {
        if ( a[i] == b[k] )
        {
            sol[++poz] = a[i];
            i-- ;
            k-- ;
            continue;
        }
        if ( best [i][k-1] < best[ i-1][k] )
        {
            i--;
        }
        else
        k--;
    }
    afis2(sol,poz);
}
int main ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    read();
    solve();
    find_sol();
    return 0;
}
