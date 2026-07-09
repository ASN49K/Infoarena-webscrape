#include <fstream>
using namespace std;


int main()
{
 ifstream f("euclid2.in");
 ofstream g("eucild2.out");

  int n,x,y,r;
  f>>n;

  for(int i=0; i<n; i++)
  {
   f>>x>>y;
    while(b!=0)
    {
     r = a%b;
     a = b;
     b = r;
    }
   g<<r<<endl;
  }
}
