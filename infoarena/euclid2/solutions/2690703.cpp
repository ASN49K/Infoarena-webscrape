#include <fstream>
using namespace std;
bool ciur[2000005];
int main()
{
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");
  int t,a,b,c;
  fin>>t;
  for(int i=1;i<=t;i++)
  {
      fin>>a>>b;
      while(b!=0)
      {
          c=a%b;
          a=b;
          b=c;
      }
      fout<<a<<'\n';
  }
    return 0;
}
