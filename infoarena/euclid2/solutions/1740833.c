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
    FILE *open,*close;
    int n , i , j , k;
    open = freopen("euclid2.in","r+",stdin);
    close = freopen("euclid2.out","w+",stdout);

    scanf("%i",&n);

    for(k=0;k<n;k++)
    {
        scanf("%i %i",&i,&j);
        if(i<j)
           Euclid(j,i);
        else
            Euclid(i,j);
    }


    fclose(open);
    fclose(close);
    return 0;
}
