#include <stdio.h>
using namespace std;

int main()
{
    long a, b, x, r = 1;
    long nr_perechi;
    
    FILE *in = fopen("euclid2.in", "r");
    FILE *out = fopen("euclid2.out", "w");
    
    fscanf(in, "%ld", &nr_perechi);
    
    for(int i = 1; i <= nr_perechi; i++)
    {
            fscanf(in, "%ld", &a);
            fscanf(in, "%ld", &b);
            
            if(a>b)
            {
                   x = b;
                   b = a;
                   a = x;
            }
            
            r = 1;
            while(r != 0)
            {
                      r = a%b;
                      a = b;
                      b = r;
            }   
            
            fprintf(out, "%ld\n", a);         
    }
    
    return 0;
}
