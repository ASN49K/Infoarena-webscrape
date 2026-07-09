# include <stdio.h>
# define InFile "euclid2.in"
# define OutFile "euclid2.out"

int main()
{
    freopen(InFile,"r",stdin);
    freopen(OutFile,"w",stdout);

    int T,a,b,i,r;

    scanf("%d",&T);
    for( i = 1 ; i <= T ; ++i )
    {
        scanf("%d %d",&a,&b);
        while( b != 0 )
        {
            r = a%b;
            a = b;
            b = r;
        }
        printf("%d\n",a);
    }

    return 0;
}
