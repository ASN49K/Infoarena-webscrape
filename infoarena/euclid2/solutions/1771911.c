#include <stdio.h>
int T, A, B;
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
int main(void)
{int i;
    FILE* euclid1=fopen("euclid2.in", "r");
    FILE* euclid2=fopen("euclid2.out", "w");
    fscanf(euclid1,"%d",&T);
    for(i=0;i<T;i++)
    {fscanf(euclid1,"%d %d", &A, &B);
        fprintf(euclid2,"%d\n", gcd(A, B));
    }
fclose(euclid1);
fclose(euclid2);
    return 0;
}
