//    Euclid


#include <cstdio>

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,a,b,aux;
    scanf("%d", &n);
    
    for( ; n; --n)
    {
        scanf("%d %d", &a, &b);
        while(b)
        {
            aux =a;
            a =b;
            b =aux %b;
        }
        printf("%d\n", a);
    }
    
    fclose(stdout); 
    
    return 0;
}
