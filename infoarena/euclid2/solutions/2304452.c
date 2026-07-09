#include<stdio.h>


int euclid(unsigned , unsigned );

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

int euclid(unsigned a, unsigned b){
unsigned r;
 while(b){
    r=a%b;
    a=b;
    b=r;
 }
 return a;
}
