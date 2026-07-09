#include <stdio.h>
#include <stdlib.h>
    int cmmdc(int a, int b){
        int aux;
        if(a>b){
           aux=a;
           a=b;
           b=aux;
        }
        if(b%a==0){
            return a;
        }
        int d=a/2;
        while(d>=1){
            if(a%d==0 && b%d==0){
                return d;
            }
            d--;
        }
    }
int main()
{
    int n, a, b, x=1;
    FILE *r, *w;
    r = fopen("euclid.in", "r");
    w = fopen("euclid.out", "w");
    fscanf(r, "%d", &n);
    while(x<=n){
        fscanf(r, "%d%d", &a, &b);
        fprintf(w, "%d\n", cmmdc(a, b));
        x++;
    }
    return 0;
}
