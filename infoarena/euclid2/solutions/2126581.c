#include <stdio.h>
#include <stdlib.h>

long int euclid2(int a, int b)
{ if(a==0)
    return b;
    else if(b==0)
    return a;
    euclid2(b,a%b);
}
void swap(int a,int b)
{
    a=b-a;b=b-a;a=a+b;
}
int main()
{   FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    long int a,b;
    int T;
    fscanf(f,"%d",&T);
    int s=1;
    while(s<=T)
        {fscanf(f,"%ld",&a);
        fscanf(f,"%ld",&b);
        if(a<b)
            swap(a,b);
        fprintf(g,"%ld\n",euclid2(a,b));
        s+=1;}
        fclose(f);
        fclose(g);
        return 0;
}
