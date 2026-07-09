#include <iostream>
#include<stdio.h>
using namespace std;
int a,b,n,i;
int euclid(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    FILE *f1,*f2;
    f1=fopen("in.txt","r");
    f2=fopen("out.txt","w+");
    fscanf(f1,"%d",&n);
    for(i=1;i<=n;i++)
        {
            fscanf(f1,"%d %d",&a,&b);
            fprintf(f2,"%d ",euclid(a,b));
            fprintf(f2,"\n");
        }
    return 0;
}
