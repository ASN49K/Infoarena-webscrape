#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{ 
  unsigned long x,y,a,b;
  int r;  
  f>>a>>b;
  f.close();
  x=a; y=b; r=x%y;
  while(r!=0)
  { a=b;  
    b=r;  
    r=a%b; 
  }
  if(b==1)
    g<<(b=0);
   else g<<b;
  g.close();
  return 0;
}
