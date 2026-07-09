#include<stdio.h>

int euclid(int a,int b)
{
int aux;
while(b)
  {
  aux=a;
  a=b;
  b=aux%a;
  }
return a;
}

int main()
{
int T;
FILE *pin=fopen("euclid2.in","r");
FILE *pout=fopen("euclid.out","w");
fscanf(pin,"%d",&T);
int a,b;
for(int i=1;i<=T;i++)
  {fscanf(pin,"%d",&a);
  fscanf(pin,"%d",&b);
  fprintf(pout,"%d",euclid(a,b));}
fclose(pout);
fclose(pin);
return 0;
}
