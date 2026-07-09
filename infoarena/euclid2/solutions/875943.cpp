#include<stdio.h>
#include<stdlib.h>


long cmmdc(long a,long b)
 {
     if(b==0) return a;

return cmmdc(b,a%b);
}


int main()
{
    long a,b,T;
    FILE *f,*g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d",&T);
    while(T){
    fscanf(f,"%d",&a);
    fscanf(f,"%d",&b);
    fprintf(g,"%d\n",cmmdc(a,b));
    T--;
    }
return 0;
}
