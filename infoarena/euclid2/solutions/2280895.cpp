#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
  int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int t,a,b,i;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++){
      fin>>a>>b;
      fout<<cmmdc(a,b)<<"\n";
    }
}
