#include<iostream>
#include<stdio.h>
using namespace std;
int x,y,n,i;
FILE *f,*g;
int main()
{
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%d\n",&n);
    for(i=0;i<n;i++)
     {
         fscanf(f,"%d%d",&x,&y);
         while(x!=y)
     {
         if(x>y)
         x=x-y;
         else
         y=y-x;
     }
     fprintf(g,"%d\n",x);
     }




}
