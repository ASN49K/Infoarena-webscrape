#include <cstdio>

inline unsigned cmmdc(unsigned a, unsigned b)
{while(a*b)
   if(a>b) a=a%b;
      else b=b%a;
 if(a) return a;
 return b;
}


int main()
{   unsigned t, a, b;
    FILE *f=fopen("euclid2.in", "r"), *g=fopen("euclid2.out", "w");
    fscanf(f, "%d", &t);
    
    for(int i=1; i<=t; i++)
       {fscanf(f, "%d %d", &a, &b);
        fprintf(g, "%d\n", cmmdc(a, b)); 
        }
        
    fclose(f);
    fclose(g);
    
    return 0;
}
