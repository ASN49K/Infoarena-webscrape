#include<fstream>
#include<iostream>
using namespace std;
long n;
long cmmdc(long a,long b)
  {
    if(a%b==0) return b;else return cmmdc(b,a%b);
  }
int main()
  {
    FILE* d=fopen("euclid2.in","r");FILE* o=fopen("euclid2.out","w");
    fscanf(d,"%d",&n);
    long x;long y;
    for(long i=1;i<=n;i++)
      {
        fscanf(d,"%d",&x);
        fscanf(d,"%d",&y);
        fprintf(o,"%d\n",cmmdc(x,y));
      }
    fclose(d);fclose(o);
    return 0;
  }
