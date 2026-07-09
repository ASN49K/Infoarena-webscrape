#include<stdio.h>

int euclid ( int a, int b ){
    int c = -1;
    while( c != 0 ){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    FILE *in = fopen("euclid2.in", "r"), *out = fopen("euclid2.out", "w");
    int n;
    fscanf(in,"%d", &n);
    for( int i = 0; i < n; i++ ){
        int a, b;
        fscanf(in, "%d%d", &a, &b);
        fprintf(out,"%d\n", euclid(a, b) );
    }
    return 0;
}

