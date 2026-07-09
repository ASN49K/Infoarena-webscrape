#include <stdio.h>

int main()
{
    int a, b, comun, aux, T;
    
    freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
    
    scanf("%d", &T);	
    for (T; T > 0; T--)
	{		
		scanf("%d %d", &a, &b);
        if ( b < a)
        {
                aux = a;
                a = b;
                b = aux;
        }
        
        if(b % a == 0)
        {
             printf("%d\n", a);
             continue;
         }
        else
        {
        while((b % a) != 0)
        {
                aux = a;
                a = b / aux;
                b = b % aux; 
                aux = b%a;        
        }
        printf("%d\n",b);
        }
    }
    return 0;
}
