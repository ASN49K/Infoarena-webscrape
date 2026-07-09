#include<stdio.h>
void main(){
FILE *f,*g;
long d,i,r,t;
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
fscanf(f,"%1d",&t);
fscanf(f,"%1d%1d",&d,&i)
while(t){t--;
r=d%i;
while(!r){d=i;i=r;r=d%i;}fprintf(g,"%1d\n",i)}}
fclose(f);fclose(g)}