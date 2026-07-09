#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE* si=fopen("euclid2.in","r");
    FILE* so=fopen("euclid2.out","w");
    int n;
    fscanf(si,"%i",&n);
    unsigned int a,b,r;
    int i;
    for(i=0;i<n;++i)
    {
        fscanf(si,"%u %u",&a,&b);
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fprintf(so,"%u\n",b);
    }
}
