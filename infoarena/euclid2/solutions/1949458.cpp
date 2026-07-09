#include <fstream>

using namespace std;

int gcd (int a, int b)
{
   while(b)
   { 
      int r;
      r=a%b;
      a=b;
      b=r;
   }
  
  return a;
}


int main()
{
   ifstream fin("euclid2.in");
   ofstream fout("euclid2.out");
   
   int t, a,b;
   fin>>t;
   for(int i=0; i<t; i++)
   { 
         fin>>a>>b;

     fout<<gcd(a,b)<<"\n";
   }
   
  return 0;
}
