#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
int T,r,i,j;

f>>T;

for(;T;--T)
{
   f>>i>>j;
   r=i%j;

   while (r!=0)
  {
   i=j;
   j=r;
   r=i%j;
  }

  g<<j<<endl;
}
f.close();
g.close();

return 0;
}
