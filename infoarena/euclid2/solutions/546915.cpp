#include<cstdio>
int main(){int n,a;FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");fscanf(f,"%d",&n);for(int i=n; i>0; i--){fscanf(f,"%d",&a);fscanf(f,"%d",&n);int c;if(n>a){c=a;a=n;n=c;}while(n!=0){c=n;n=a%n;a=c;}fprintf(g,"%d\n",a);}fclose(f);fclose(g);return 0;}
