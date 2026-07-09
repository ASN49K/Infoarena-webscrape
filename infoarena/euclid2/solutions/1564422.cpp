#include <cstdio>

using namespace std;

int cmmdc(int a, int b){
    if(a % b == 0)
        return b;
    return cmmdc(b, a % b);
}

int main()
{
    FILE *fin = fopen("euclid2.in", "r");
    FILE *fout = fopen("euclid2.out", "w");

    int n, a, b;

    fscanf(fin, "%d", &n);
    for(int i=1; i<=n; ++i){
        fscanf(fin, "%d%d", &a, &b);
        fprintf(fout, "%d\n", cmmdc(a, b));
    }

    return 0;
}
