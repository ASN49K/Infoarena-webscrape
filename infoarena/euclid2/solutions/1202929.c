#include <stdio.h>
#include <stdlib.h>

FILE *f,*g;
int main()
{
    f = fopen("euclid2.in","r");
    g = fopen("euclid2.out","w");
    int a,b,n,i,c,T;
    c = 1 ; T = 0;
    fscanf(f,"%d",&n);
    for(i = 0 ; i< n ; i++)
    {
     fscanf(f,"%d%d",&a,&b);
      while(c != 0 && a>=2 && b <= 2000000000)
      {
          if(a%b == 0)
          {
           fprintf(g,"%d\n",b);
           T++;
           break;
          }

          else
            {
             c = a % b;
             a = b;
             b = c;
            }
        if (T >1000000)
            break;
      }


    }


    fclose(f);
    fclose(g);
    return 0;
}
