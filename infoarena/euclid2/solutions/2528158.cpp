#include <bits/stdc++.h>

using namespace std;
FILE *in, *out;

int euclid(int a, int b) {
    if(!b) return a;
    return euclid(b, a%b);
}

int main()
{
    in = fopen("euclid2.in", "r");
    out = fopen("euclid2.out", "w");

    int T;
    fscanf(in, "%d", &T);
    for(int i = 1; i <= T; ++i) {
        int x, y;
        fscanf(in, "%d%d", &x, &y);
        fprintf(out, "%d\n", euclid(x, y));
    }
    fclose(in);
    fclose(out);
    return 0;
}
