#include <iostream>
#include<stdio.h>
using namespace std;
int t,i;
long a,b;
int main()
{
    FILE*f1;
    FILE*f2;
    f1=fopen("euclid2.in","rb");
    f2=fopen("euclid2.out","wb");
    fscanf(f1,"%d",&t);
    for(i=1;i<=t;i++)
    {
        fscanf(f1,"%ld%ld",&a,&b);
        while(a!=b)
        {
            if(a<b)b-=a;
            else a-=b;
        }
        fprintf(f2,"%ld\n",a);
    }
    return 0;
}
