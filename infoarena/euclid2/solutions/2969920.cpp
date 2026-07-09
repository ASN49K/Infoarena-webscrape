#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int, int);
int a, b, n;

int main()
{
  int i;
  fin>>n;
  for(i=1; i<=n; i++)
  {
    fin>>a>>b;
    fout<<euclid(a, b)<<'\n';
  }
  return 0;
}

int euclid(int a, int b)
{
  int r;
  while(b)
  {
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}
