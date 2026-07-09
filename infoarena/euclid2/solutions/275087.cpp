#include <iostream.h>
#include<fstream.h>
int main()
{  ifstream f("euclid2.in");
   ofstream g("euclid2.out");
    long t,a,b,r;
      f>>t;
      while(t)
      {        f>>a>>b;
               while (b)
               {r=a%b;a=b;b=r;}g<<a<<endl; t--;}
      g.close();// f.close();
}
