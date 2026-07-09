#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T, a, b;
int Cmmdc(int a, int b)
{
if (b==0) return a;
return Cmmdc(b, a % b);
}
int main()
{
fin>>T;
for (; T!=0; --T)
{
fin>>a>>b;
fout<<Cmmdc(a,b);
fin.close();
fout.close();
}       
return 0;
}
