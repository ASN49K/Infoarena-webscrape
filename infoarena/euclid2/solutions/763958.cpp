#include <stdio.h>

using namespace std;

int cmmdc (int a, int b) {
    int aux;
    while (b != 0) {
          aux = a % b;
          a = b;
          b = aux;
    }
    return a;
}

int main()
{
    FILE* f = fopen("euclid2.in", "r");
    FILE* g = fopen("euclid2.out", "w");
    
    int t;
    int a, b, c;
    fscanf(f, "%d", &t);
    
    for (int i = 0; i < t; i++) {
        fscanf(f, "%d%d", &a, &b); 
        c = cmmdc(a, b);
        fprintf(g, "%d\n", c);
    }
    
    
    
    return 0;
}
