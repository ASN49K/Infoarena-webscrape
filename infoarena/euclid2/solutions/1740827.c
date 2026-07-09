#include <stdio.h>
#include <stdlib.h>

int Euclid (int a ,int b )
{
    int r;
    if(b==0)
        return a;
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
            printf("%i\n",Euclid(j,i));
        else
            printf("%i\n",Euclid(i,j));
    }


    fclose(open);
    fclose(close);
    return 0;
}
