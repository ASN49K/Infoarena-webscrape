#include <iostream>
#include <fstream>
using namespace std;

int main()
{long i,T;
 long long r,a,b;
 ifstream f("euclid2.in.txt");
 ofstream g("euclid2.out.txt");
 f>>T;
 for(i=1;i<=T;i++)
    {f>>a;
     f>>b;
     do
      {r=a%b;
      a=b;
      b=r;}
    while(r!=0);
    g<<a<<endl;}

    return 0;
}
