#include <stdio.h>
#include <stdlib.h>
int cmmmdc(int a , int b){
    int c = a % b ;
    while ( c != 0){
        a = b ;
        b = c ;
        c = a % b ; 
    }
    return b ;
}
int main(){
    FILE * in = fopen("euclid2.in","r");
    FILE * out = fopen("euclid2.out","w");
    int T ;
    fscanf(in,"%d\n",&T);
    int i ,a,b;
    for ( i  = 0 ; i< T  ; i++){
        fscanf(in,"%d %d\n",&a,&b);
        fprintf(out, "%d\n",cmmmdc(a,b));
    }
    fclose(in);
    fclose(out);
    return 0 ;
}