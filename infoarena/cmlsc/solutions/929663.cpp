#include<stdio.h>
int a[1025] , b[1025] , d[1025][1025] , v[1025];
int n , m;
int max(int a , int b)
{
    if(a > b)
        return a;
    return b;
}
void dinamic()
{
    for (int i=1 ; i<=n ; ++i)
        for (int j=1 ; j<=m ; ++j)
            if(a[i] == b[j])
                d[i][j]=1 + d[i - 1][j - 1];
            else
                d[i][j]=max(d[i - 1][j] , d[i][j - 1]);
}
void reconst()
{
    for (int i=n , j=m ; d[i][j]>0 ;)
        if(a[i] == b[j])
            v[++v[0]]=a[i] , --i , --j;
        else
            if(d[i-1][j] > d[i][j-1])
                --i;
            else
                --j;
}
int main()
{
    ///freopen("cmlsc.in" , "r" , stdin);
   /// freopen("cmlsc.out" , "w" , stdout);
    scanf("%d %d" , &n , &m);
    for (int i=1 ; i<=n ; ++i)
        scanf("%d" , &a[i]);
    for (int i=1 ; i<=m ; ++i)
        scanf("%d" , &b[i]);
    dinamic();
    printf("%d\n" , d[n][m]);
    reconst();
    for (int i=v[0] ; i>=1 ; --i)
        printf("%d " , v[i]);
    return 0;
}
