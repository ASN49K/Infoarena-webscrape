#include <iostream>
#include <stdio.h>

using namespace std;

FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");

int euclid(int a,int b)
 {
     if (b==0){
       return a;}
        else euclid(b,a%b);


 }

int a,b,d,n,i;

int main()
{
    fscanf(f,"%d",&n);
    for (i=1;i<=n;i++){
       fscanf(f,"%d%d",&a,&b);
       d=euclid(a,b);
       fprintf(g,"%d\n",d);
    }



    return 0;
}
