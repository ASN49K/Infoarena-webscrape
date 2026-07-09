#include<stdio.h>
int main()
{long i,t,a,b;FILE*f=fopen("euclid2.in","r"), *g=fopen("euclid2.out","w");if(f==NULL){return 0;printf("NU exista.");}fscanf(f,"%ld",&t);for(i=1;i<=t;i++){fscanf(f,"%ld %ld",&a,&b);if(a!=b){while(a!=b){if(a>b) a=a-b; else b=b-a;}fprintf(g,"%ld\n",a);}else fprintf(g,"%ld\n",a);}}
