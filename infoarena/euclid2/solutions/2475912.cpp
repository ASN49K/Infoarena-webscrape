#include <stdio.h>

long long cmmdc(long long x, long long y){
    long long temp;
    while( y != 0 ){
        temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

int main(){
    int n;
    FILE *input = fopen("euclid2.in", "r");
    FILE *output = fopen("euclid2.out", "w");
    fscanf(input, "%d", &n);
    for(int i = 0; i < n; i++){
        long long x, y;
        fscanf(input, "%lld %lld", &x, &y);
        fprintf(output, "%lld\n", cmmdc(x, y));
    }
    fclose(input);
    fclose(output);
    return 0;
}