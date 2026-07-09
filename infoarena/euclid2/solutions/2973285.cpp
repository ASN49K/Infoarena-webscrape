#include <iostream>
using namespace std;
FILE *in = fopen("euclid2.in", "r"), *out = fopen("euclid2.out", "w");

int T, A, B;

int main()
{
    fscanf(in, "%d", &T);
    for (int i = 0; i < T; ++i){
        fscanf(in, "%d %d", &A, &B);
        while (A && B) {
            if (A > B)
                A = A % B;
            else
                B = B % A;
        }
        fprintf(out, "%d\n", !B ? A : B);
    }
    return 0;
}
