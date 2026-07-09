#include <stdio.h>
int gcd(int a, int b){
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}
int main()
{
    int a,b,n,i;
    FILE *in = fopen("euclid2.in", "r");
    fscanf(in,"%d\n", &n);
    FILE *out = fopen("euclid2.out","w");

    for (i=0;i<n;i++){
        fscanf(in,"%d %d\n", &a,&b);
        fprintf(out,"%d\n", gcd(a,b));
    }
    fclose(in);
    fclose(out);
    return 0;
}
