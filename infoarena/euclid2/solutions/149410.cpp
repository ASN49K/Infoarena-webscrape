#include<stdio.h>
int a,b,r;

int main(){

FILE *f=fopen("euclid2.in","r");
fscanf(f,"%d %d",&a,&b);
fclose(f);

while(b!=0){
r=a%b;
a=b;
b=r;
}



FILE *g=fopen("euclid2.out","w");
fprintf(g,"%d",a);
fclose(g);

return 0;
}
