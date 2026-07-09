#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
int T,r,a,b;

f>>T;

for(;T;--T)
{
   f>>a>>b;
   while (b)
  {
   r=a%b;
   a=b;
   b=r;
  }
g<<a<<endl;
}
f.close();
g.close();

return 0;
}
