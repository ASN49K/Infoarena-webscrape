#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,sol[1001],a[1001],b[1001],d[1001][1001],k;
void dinamic ()
{
    for (int i=1 ; i<=n ; ++i)
        for (int j=1 ; j<=m ; ++j)
            if(a[i] == b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j] , d[i][j-1]);
}
void reconst()
{
    int i=n , j=m;
    for ( ; d[i][j] > 0 ; )
        if(a[i] == b[j])
            sol[++k]=a[i] , --i , --j ;
        else
            if(d[i][j-1]>   d[i-1][j])
                --j;
            else
                --i;
}
int main()
{
    freopen("cmlsc.in" , "r" , stdin);
    freopen("cmlsc.out" , "w" , stdout);
    scanf("%d %d" , &n , &m);
    for (int i=1 ; i<=n ; ++i)
        scanf("%d" , &a[i]);
    for (int i=1 ; i<=m ; ++i)
        scanf("%d" , &b[i]);
    dinamic();
    reconst();
    printf("%d\n" , k);
    for (int i=k ; i>=1 ; --i)
        printf("%d " , sol[i]);
    return 0;
}
/*
campion:
dezbateri
codul
comun
infoarena:
sortare topologica
UVA:
speedsheet 196
Vianu arena
skyline
maxim
carti
roboti


*/
