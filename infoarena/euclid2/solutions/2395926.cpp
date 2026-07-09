#include <stdio.h>

unsigned euclid(unsigned x, unsigned y)
{
    if(x==y)
        return x;
    else if(x>y)
        return euclid(x-y, y);
    else
        return euclid(x, y-x);
}   

int main()
{
    FILE* input  = fopen("euclid2.in", "r");
    FILE* output = fopen("euclid2.out", "w");
        
    unsigned  n;
    fscanf(input, "%d", &n);  
    
    for(unsigned i=0; i<n; i++)
    {
        unsigned x, y;
        fscanf(input, "%d %d", &x, &y);
        fprintf(output, "%d\n", euclid(x, y));
    }
    
    fclose(input);
    fclose(output);

}
