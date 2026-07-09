#include <stdio.h>
#include <stdlib.h>

int T, A, B;

int cmmdc(int a, int b){
    if(!b)
        return a;
    else
        return cmmdc(b, a % b);
}

/*int main()
{
    FILE *input, *output;

    input = fopen("euclid2.in", "r");
    output = fopen("euclid2.out", "w");

    int a[100000];
    int n;

    fscanf(input, "%d", &n);

    for(int i = 0; i < 2 * n; i++)
        fscanf(input, "%d", &a[i]);

    for(int i = 0; i < 2 * n - 1; i += 2){
        fprintf(output, "%d\n", cmmdc(a[i], a[i+1]));
    }

    return 0;
}*/

int main()
{
    freopen("euclid2.in", "w", stdin);
    freopen("euclid2.out", "r", stdout);

    scanf("%d", &T);
    for(; T; T--){
        scanf("%d %d", &A, &B);
        printf("%d\n", cmmdc(A,B));
    }

    return 0;
}
