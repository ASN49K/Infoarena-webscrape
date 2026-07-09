#include<stdio.h>
#include<stdlib.h>


int cmmdc(int a,int b)
 {
     while(a!=b)
      {
                if(a>b) a-=b;
                else b-=a;
                }
return a;
}


int main()
{
    int a,b,T;
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
