#include <fstream>
using namespace std;
ifstream fin("eulcid2.in");
ofstream fout("euclid2.out");

unsigned long long t,a,b,c;

int main()
{
fin>>t;
for(;t;t--)
 {
 fin>>a>>b;
 while(b)
  {
  c=b;
  b=a%c;
  a=c;
  }
 fout<<a<<'\n';
 }
fin.close();
fout.close();
return 0;
}
