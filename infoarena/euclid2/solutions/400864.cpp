#include <stdio.h>
#include <stdlib.h>
FILE *f1,*f2;
long a,b,t,i;
int main()
{f1=fopen("euclid2.in","r");
 f2=fopen("euclid2.out","w");
 fscanf(f1,"%ld\n",&t);
 for(i=1;i<=t;i++)
{
    fscanf(f1,"%ld %ld\n",&a,&b);
    while(a!=b)if(a>b)a-=b;
                 else b-=a;
    fprintf(f2,"%ld\n",a);
}
 fclose(f1);
 fclose(f2);
return 0;
}
