#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    int r; 
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int main(){
    
    FILE *input = fopen("euclid2.in", "r");
    FILE *output = fopen("euclid2.out", "w");
    int pairs;

    fscanf(input, "%d", &pairs);
    int a, b;
    for(; pairs-- > 0;){
        fscanf(input, "%d%d", &a, &b);
        fprintf(output, "%d\n", gcd(a,b));
    }

    fclose(input);
    fclose(output);
    return 0;
}
