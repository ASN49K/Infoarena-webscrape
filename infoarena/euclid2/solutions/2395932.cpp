#include <stdio.h>

unsigned cmmdc(unsigned x, unsigned y)
{
    if(!y) return x;
    else   return cmmdc(y, x%y);
}   

int main()
{
    FILE* input  = fopen("euclid2.in", "r");
    FILE* output = fopen("euclid2.out", "w");
        
    unsigned  n;
    if( fscanf(input, "%d", &n) == EOF )
        return -1;  
    
    for(unsigned i=0; i<n; i++)
    {
        unsigned x, y;
        if( fscanf(input, "%d %d", &x, &y) == EOF )
            return -1;
        fprintf(output, "%d\n", cmmdc(x, y));
    }
    
    fclose(input);
    fclose(output);

}
