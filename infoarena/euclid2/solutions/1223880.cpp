#include <cstdio>

using namespace std;

FILE * input;
FILE * output;

void gcd(int a, int b)
{
    while(a && b)
        if(a > b)
            a %= b;
        else
            b %= a;

    if(a > b)
        fprintf(output, "%d\n", a);
    else
        fprintf(output, "%d\n", b);
    }

void read() {
    int a, b, numberOfInputs;
    fscanf(input, "%d", &numberOfInputs);

    for(int i = 1; i<= numberOfInputs; i++) {
        fscanf(input, "%d %d", &a, &b);
        gcd(a, b);
    }
}

int main() {
    input = fopen("euclid2.in", "r");
    output = fopen("euclid2.out", "w");

    read();

    return 0;
}
