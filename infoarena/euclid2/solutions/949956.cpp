#include <algorithm>
#include <fstream>
using namespace std;

#define FIN	"euclid2.in"
#define FOUT	"euclid2.out"

ifstream fin(FIN);
ofstream fout(FOUT);

int gcd(int a, int b)
{
  if(a<b)
    swap(a, b);

  while(b)
  {
    int r=a%b;
    a=b;
    b=r;
  }

  return a;
}

int main()
{
  int n, a, b;

  for(fin>>n; n--;)
  {
    fin>>a>>b;
    fout<<gcd(a, b)<<"\n";
  }

  return 0;
}
