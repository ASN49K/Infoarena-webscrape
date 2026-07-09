#include<stdio.h>

int a,b,t,x;

int main (){

FILE*f=fopen("euclid2.in","r");
FILE*g=fopen("euclid2.out","w");

fscanf(f,"%d",&t);

for (t;t>=1;t--)


{
fscanf(f,"%d %d",&a,&b);
while(b!=0)
{
x=a;
a=b;
b=x%b;
}

fprintf(g,"%d\n",a);
}

fclose(f);
fclose(g);
return 0;
}
