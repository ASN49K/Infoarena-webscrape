#include <iostream>

using namespace std;

int main()
{
    FILE *f=fopen("euclid2.in", "r");
    FILE *g=fopen("euclid2.out", "w");

    int a,b,r;
    fscanf(f,"%d %d" , &a , &b);

    while(b!=0){
       r=a%b;
       a=b;
       b=r;
               }
      fprintf(g, "%d\n" , a);
      fclose(f);
      fclose(g);

    return 0;
}
