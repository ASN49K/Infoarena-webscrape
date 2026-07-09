#include<stdio.h>
int main()
{int i,t,a,b;FILE*f=fopen("euclid2.in","r"), *g=fopen("euclid2.out","w");if(f==NULL){return 0;printf("NU exista.");}fscanf(f,"%d",&t);for(i=1;i<=t;i++){fscanf(f,"%d %d",&a,&b);if(a!=b){while(a!=b){if(a>b) a=a-b; else b=b-a;}fprintf(g,"%d\n",a);}else fprintf(g,"%d\n",a);}}
