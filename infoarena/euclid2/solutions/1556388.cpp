#include <cstdio>

using namespace std;

int euclid ( int a , int b )
{
    int c ;
    while ( b )
    {
        c = a % b ;
        a = b ;
        b = c ;
    }
    return a ;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n , x , y  , rasp ;
    scanf("%d",&n);
    for ( int i = 1 ; i <= n ; i++ )
    {
        scanf("%d %d",&x,&y);
        rasp = euclid(x,y);
        printf("%d\n",rasp);
    }
    return 0 ;
}
