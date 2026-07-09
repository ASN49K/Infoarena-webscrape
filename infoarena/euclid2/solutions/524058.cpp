#include<iostream>
using namespace std;

long int n;
FILE *g = fopen("euclid2.out","w");

long long euclid(unsigned long int a,unsigned long int b)
{
     while(a && b)
     {
          long long c = a%b;
          a = b;
          b = c;
     }
     return a;
}

void citire(void)
{
     unsigned long int a;
     unsigned long int b;
     FILE *f = fopen("euclid2.in","r");
     
     fscanf(f,"%d",&n);
     for(int i=1;i<=n;i++)
     {
        fscanf(f,"%u %u",&a,&b);
        fprintf(g,"%u\n",euclid(a,b));
     }
     
     fclose(f);
}

int main()
{
    citire();
    
    fclose(g);
}
