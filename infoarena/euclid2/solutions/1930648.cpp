#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned long long t,a,b,c;

int main()
{
fin>>t;
while(t)
 {
 fin>>a>>b;
 while(b)
  {
  c=a;
  a=b;
  b=c%b;
  }
 fout<<a<<'\n';
 t--;
 }
fin.close();
fout.close();
return 0;
}
