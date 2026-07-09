#include <iostream>
#include <fstream>

using namespace std;

int t;
long a,b;

long euclid(long a,long b)
{
   long r;
   r = a%b;
   while(r)
   {
    a=b;
    b=r;
    r = a%b;
    }
   return b;     
}

int main()
{
  
  int i;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f >> t;
  for(i=0;i<t;i++)
  {
     f >> a >> b;
     g << euclid(a,b) << "\n";                    
   }
  f.close();
  g.close(); 
  return 0;   
}
