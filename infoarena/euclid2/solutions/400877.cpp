#include <stdio.h>
FILE *f1,*f2;
long a,b,t,i;
int main()
{f1=fopen("euclid2.in","r");
 f2=fopen("euclid2.out","w");
 fscanf(f1,"%ld\n",&t);
 for(;t;t--)
{
    fscanf(f1,"%ld %ld\n",&a,&b);
    while(a)
    {
        i=a;
        a=b%a;
        b=i;
    }
   fprintf(f2,"%ld\n",b);
}
 fclose(f1);
 fclose(f2);
return 0;
}
