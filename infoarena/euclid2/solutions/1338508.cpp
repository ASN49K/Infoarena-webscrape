# include<cstdio>
using namespace std;
FILE *f=freopen("euclid2.in","r",stdin);
FILE *g=freopen("euclid2.out","w",stdout);
int algr( int a, int b)
{
    if( !b ) return a;
    return algr(b, a % b);
}
int main()
{
    int t,i,a,b;
    scanf("%d",&t);
    for( i = 0 ; i <= t - 1 ; i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",algr(a,b));
    }
    return 0;
}
