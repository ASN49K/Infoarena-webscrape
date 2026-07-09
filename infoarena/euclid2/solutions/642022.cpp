#include <cstdio>

inline unsigned cmmdc(unsigned a, unsigned b)
{ long long p=a*b;
 while(p)
 { if(a>b) a=a%b;
     else b=b%a;
   p=a*b;
  }
 if(a) return a;
 return b;
}


int main()
{   unsigned t, a, b;
    FILE *f=fopen("euclid2.in", "r"), *g=fopen("euclid2.out", "w");
    fscanf(f, "%u", &t);
    
    for(unsigned i=1; i<=t; i++)
       {fscanf(f, "%u %u", &a, &b);
        fprintf(g, "%u\n", cmmdc(a, b)); 
        }
        
    fclose(f);
    fclose(g);
    
    return 0;
}
