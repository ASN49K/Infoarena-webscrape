#include<fstream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int euclid(unsigned long a, unsigned long b)
{
  if(!b) return a;
   else euclid(b, a%b); 
}

int main()
{
  int t;
  unsigned long a,b;
  fi>>t;
  for(int i=0;i<t;i++)
  {
   fi>>a>>b;
   if(a>=b) fo<<euclid(a,b)<<'\n';
     else fo<<euclid(b,a)<<'\n';
  }
  fi.close();
  fo.close();
 return 0;
}
