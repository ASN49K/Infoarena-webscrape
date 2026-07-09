#include<cstdio>
int main(){int n,a;FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");fscanf(f,"%d",&n);for(int i=n; i>0; i--){fscanf(f,"%d",&a); fscanf(f,"%d",&n);if(a>=n){a=a%n;if(a==0)a=n;}else{n=n%a;a=n;}fprintf(g,"%d\n",a);}fclose(f);fclose(g);return 0;}
