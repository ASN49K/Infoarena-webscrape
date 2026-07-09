#include <iostream>
#include <fstream>
using namespace std;

FILE* f = fopen("euclid.in", "r");
FILE* g = fopen("euclid.out", "w");

int cmmdc(int a, int b)
{
    while (b != 0) {
        int aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

void do_test()
{
    int n, m;
    fscanf(f, "%d %d\n", &n, &m);
    fprintf(g, "%d\n", cmmdc(n, m));
}

int main()
{
    int t;
    fscanf(f, "%d\n", &t);
    for (int i = 1; i <= t; i++) {
        do_test();
    }

    return 0;
}
