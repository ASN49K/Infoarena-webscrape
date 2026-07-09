#include <fstream>
#include <fstream>

using namespace std;

int n, a, b, r;

int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;

for (int i=1; i<=n; i++)
{
  f>>a>>b;
  if(a<b)

    {
     r=a;
     a=b;
     b=r;
    }

  do
    {
     r=a%b;
     a=b;
     b=r;

    } while(r>0);

  g<<a<<"\n";
}

return 0;
}
