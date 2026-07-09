#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;

int cmmdc(int a, int b) {
  while (a != b) {
    if (a > b)
      a -= b;
    else 
      b -= a;
  }
  return a;
}
void Citire()
{
	int i,x,y;
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>x>>y;
		fout<<cmmdc(x,y)<<'\n';
	}
}
int main()
{
	Citire();
	return 0;
}
