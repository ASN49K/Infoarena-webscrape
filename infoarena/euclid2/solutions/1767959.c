#include<stdio.h>

unsigned int euclid(unsigned int a, unsigned int b){

   while(b!=0){

    a=a%b;
    a=a^b;
    b=a^b;
    a=a^b;

   }
   return a;
}
int main()
{
    FILE *f,*g;
    unsigned int a=0, b=0, t=0;


    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");
    fscanf(f,"%u",&t);

    while(t>=1){

        fscanf(f,"%u",&a);
        fscanf(f,"%u",&b);
        fprintf(g,"%u\n",euclid(a,b));
        t--;
    }
}
