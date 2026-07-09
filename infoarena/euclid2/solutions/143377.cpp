#include<stdio.h>
FILE *f,*g;

unsigned long int n,m,aux,r;
unsigned long int a,b;
int main()
{
f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");
fscanf(f,"%ld %ld",&n,&m);

do
{
r=n%m;
n=m;
m=r;
}
while(r!=0);


fprintf(g,"%ld",n);
fcloseall();
return 0;

}