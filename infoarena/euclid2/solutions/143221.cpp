#include<stdio.h>
#define E FILE *f,*g;f=fopen("euclid2.in","r");g=fopen("euclid2.out","w");
#define U fscanf(f,"%ld%ld",&a,&b);
#define C while(b){c=b;b=a%b;a=c;}
#define L fprintf(g,"%ld\n",a);
#define I fcloseall();
#define D return 0;
long int a,b,c;
int main()
{
      E U C L I D
}
