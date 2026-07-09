#include<iostream>
#include<stdio.h>
using namespace std;
int x,y,n,i,r;
FILE *f,*g;
int main()
{
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d\n",&n);
    for(i=0;i<n;i++)
     {
         fscanf(f,"%d%d",&x,&y);
         while(y)
     {
         r=x%y;
         x=y;
         y=r;
     }
     fprintf(g,"%d\n",x);
     }

}
