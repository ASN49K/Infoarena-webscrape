#include<cstdio>
int main(){int n,a;FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");fscanf(f,"%d",&n);for(int i=n; i>0; i--){fscanf(f,"%d",&a);fscanf(f,"%d",&n);while((n!=0)&&(a!=0)){if(n>a){int c=a; a=n; n=c;}a-=n;}fprintf(g,"%d\n",n);}fclose(f);fclose(g);return 0;}
