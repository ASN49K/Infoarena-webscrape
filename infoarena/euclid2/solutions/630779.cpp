#include <iostream>
#include <fstream>

using namespace std;

 int cmmdc(int a,int b)
 {
     int r;
     for(;b;r=a%b,a=b,b=r);

     return a;
 }

int main()
{
    int t,a,b;
    FILE *f = fopen("euclid2.in","r");
    FILE *g = fopen("euclid2.out","w");

    fscanf(f,"%d", &t);
    for(int i=1;i<=t;i++)
     {
         fscanf(f,"%d %d", &a,&b);
         fprintf(g,"%d \n", cmmdc(a,b));
     }


    return 0;
}
