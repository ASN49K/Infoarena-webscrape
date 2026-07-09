#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std ;

int n ;
int x, sumaxor ;

int tst ;

int main()
{

    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    scanf("%d", &tst);

    while( tst-- )
    {
        scanf("%d", &n);

        sumaxor = 0 ;

        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &x);

            sumaxor ^= x ;
        }

        if( sumaxor )
            puts("DA");
        else
            puts("NU");
    }

    return 0 ;

}
