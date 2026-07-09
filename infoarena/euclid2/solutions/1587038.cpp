#include <iostream>
#include <stdio.h>
using namespace std;
FILE *f,*g;
int main()
{
    int t,i,a,b,d;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d",&t);
    for(i=1;i<=t;i++)
    {
        fscanf(f,"%d %d",&a,&b);
        while(a!=b)
        {
            if(a>b)
            {
                a=a-b;
            }
            else
            {
                b=b-a;
            }
        }
        fprintf(g,"%d\n",a);
    }
    return 0;
}
