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

        while(a%b!=0){

            a=a%b;
            aux=b;
            b=a;
            a=aux;
        }

    fprintf(w,"%d\n", b);


         n--;
    }



 return 0;
}
