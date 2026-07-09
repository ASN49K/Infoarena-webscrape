#include <iostream>
#include<fstream>
using namespace std;

int main()
{  ifstream f("euclid2.in");
   ofstream g("euclid2.out");
    long t,a,b,r;
      f>>t;
      while(t!=0)
      {        f>>a>>b;
               while (b!=0)
               {r=a%b;a=b;b=r;}g<<a<<endl; t--;}
      g.close(); f.close();
}
