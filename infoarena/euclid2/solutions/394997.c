#include <stdio.h>

int gcd(int a, int b)
{
    if(b == 0)
         return a;
    else
       return gcd(b, a % b);
}

int main()
{
    FILE *in = fopen("euclid2.in", "r");
    FILE *out = fopen("euclid2.out", "w");
    
    int T;
    fscanf(in, "%d", &T);
    int a, b;
    
    while(T != 0)
    {
       fscanf(in, "%d %d", &a, &b);
       fprintf(out, "%d\n", gcd(a, b));
       T--;
    }
    fclose(in);
    fclose(out);
    return 0;
}
