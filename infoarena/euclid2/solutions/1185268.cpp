#include<iostream>
#include<stdio.h>
using namespace std;
int euclid(int a,int b)
{
    int t;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
int main()
{
    int i,t,a,b;
    FILE *f,*g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d",&t);
    for(i=1;i<=t;i++)
    {
        fscanf(f,"%d%d",&a,&b);
        fprintf(g,"%d\n",euclid(a,b));
    }
    fclose(f);
    fclose(g);   
    return 0;
}
