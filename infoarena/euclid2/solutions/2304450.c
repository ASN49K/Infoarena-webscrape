#include<stdio.h>

typedef int recursiv;

recursiv euclid(unsigned , unsigned );

unsigned a,b;
int main(){
FILE *fpointer;
fpointer=fopen("euclid2.in","r");

fscanf(fpointer,"%d %d",&a,&b);
fclose(fpointer);

FILE *fouter;
fouter=fopen("euclid2.out","w");

fprintf(fouter,"%d",euclid(a,b));
fclose(fouter);

return 0;
}

recursiv euclid(unsigned a, unsigned b){
    if(!b)
    return a;

    return euclid(b,a%b);
}
