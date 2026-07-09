#include <stdio.h>
#include <stdlib.h>

void Euclid (int a ,int b )
{
    if(b==0)
        printf("%i\n",a);
    else
    Euclid(b,a%b);
}
int main()
{

    int n , i , j , k;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%i",&n);

    for(k=0;k<n;k++)
    {
        scanf("%i %i",&i,&j);
        Euclid(i,j);

    }

    return 0;
}
