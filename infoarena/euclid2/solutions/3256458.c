#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *r, *w;
    r=fopen("euclid2.in", "r");
    w=fopen("euclid2.out", "w");
    int a,n,m,min,i,j,aux;
    fscanf(r, "%d", &a);
    for(i=0; i < a; i++)
    {
        fscanf(r, "%d%d", &n, &m);
        while(n%m != 0)
        {
            n = n%m;
            aux = n;
            n = m;
            m = aux;
        }
        if(n%m == 0)
        {
            fprintf(w, "%d\n", m);
        }
        else
        {
            min = m/2;
            while(min>=1)
            {
                if((n%min==0) && (m%min==0))
                {
                    fprintf(w, "%d\n", min);
                    min = 1;
                }
                min--;
            }
        }
    }
    return 0;
}
