#include <iostream>
#include <fstream>
using namespace std;

FILE* f = fopen("euclid.in", "r");
FILE* g = fopen("euclid.out", "w");

int cmmdc(int a, int b){
    if (b == 0) return a;
    return cmmdc(b, a % b);
}

void do_test()
{
    int a, b;
    fscanf(f, "%d %d\n", &a, &b);
    fprintf(g, "%d\n", cmmdc(a, b));
}

int main()
{
    int t;
    fscanf(f, "%d\n", &t);
    for (int i = 1; i <= t; i++) {
        do_test();
    }

    fclose(f);
    fclose(g);
    return 0;
}
