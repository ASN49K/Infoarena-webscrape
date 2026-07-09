#include <stdio.h>
//greatest common divisor algorithm 
int euclid(int x, int y)
{
    if( y == 0){
     return x;
    }else{ 
    return euclid(y, x % y); 
    }
}

int main(void)
{
    int n, a, b;
    int r;
    FILE *in = fopen("euclid2.in", "rt");
    FILE *out = fopen("euclid2.out", "wt");

    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++){
        fscanf(in, "%d%d", &a, &b);
        r = euclid(a, b);
        fprintf(out, "%d\n", r);
    }
    fclose(in);
    fclose(out);

   return 0; 

}