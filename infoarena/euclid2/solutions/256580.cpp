//    Euclid

#include <cstdio>

int main()
{
    freopen("euclid2.in","r",stdin);
    int n,a,b,aux;
    scanf("%d", &n,);
    
    for( ; n; n--)
    {
        scanf("%d %d", &a, &b);
        while(a)
        {
            aux =a;
            a =b;
            b =aux %b;
        }
        printf("%d\n", b);
    }
    
    fclose(stdout); 
    
    return 0;
}
