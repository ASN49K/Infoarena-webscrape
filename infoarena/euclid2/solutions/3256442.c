#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, d;
    FILE *r,*w;

    r = fopen("euclid2.in", "r");
    w = fopen("euclid2.out", "w");
    fscanf("%d", n);

     while(n) {
        fscanf("%d%d", &a, b);
        if(a/2<b/2){
            d=a/2;
        }
        else{
           d=b/2;
        }
        while(d>=2){
            if((a%d==0)&&(b%d==0)){
            fprintf(w, "%d", d);
                d=1;
            }
        else{
            d=d-1;
            }
        }
        n=n-1;
     }

}
