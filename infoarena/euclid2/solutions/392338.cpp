#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int cmmdc(int a,int b)
{
    if(b==0) return a;
    else return cmmdc(b,a%b);
}
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
int main()

{    freopen("euclid2.out","w",stdout);
    int t,x,y;
    ifstream fin("euclid2.in");
     fin>>t;
     for(int i=1;i<=t;i++)
      {fin>>x>>y;
      printf("%d \n", cmmdc(x,y));
      }
      fin.close();

return 0;

}
