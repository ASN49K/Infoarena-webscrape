#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, n, d, aux;
    FILE *r,*w;
    r = fopen("euclid2.in", "r");
    w = fopen("euclid2.out", "w");

        fscanf(r, "%d", &n);
    while (n){
        fscanf(r, "%d%d", &a, &b);

        if(a<b){
            aux=b;
            b=a;
            a=aux;
        }
        if(a%b==0){
            fprintf(w, "%d\n", b);
        } else{
            d=b/2;
            while(d>=1){
                if ((a%d==0)&&(b%d==0)){
                    fprintf(w, "%d\n", d);
                    d=0;
                }
                else {
                    d--;
                }
            }
        }



         n--;
    }



 return 0;
}
