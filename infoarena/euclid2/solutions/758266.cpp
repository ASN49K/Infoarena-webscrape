#include <stdio.h>



int cmmdc(int a, int b)
{
    int aux, cmmdc = 1;
    if(b > a)
         {
             aux = a;
             a = b;
             b = aux;
              }
         
    while(a%b > 0)
    {
                       aux = b;
                       b = a % b;
                       a = aux;
                       
            }
    if (a%b == 0)
    cmmdc = b;
    return cmmdc;
    }
    
    
    int main()
    {
    FILE *f, *g;
    int n, a, b;
    f = fopen("euclid2.in", "r");
    fscanf(f, "%d", &n);
    g = fopen("euclid2.out", "w");
    for(int i = 0; i < n; i++)
            {
                fscanf(f, "%d",&a);
                fscanf(f, "%d", &b);
                fprintf(g, "%d\n", cmmdc(a, b)); 
                }
            return 0;
    }
                
