#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int Cmmdc(int a, int b);
int main()
{
int N,a,b;
fin>>N;
for(int i=0;i<N;i++)
{
fin>>a>>b;
fout<<Cmmdc(a,b);}
fin.close();
fout.close();
    return 0;
}

int Cmmdc(int a, int b)
{
    if (a=0) return b;
if (b=0) return a;
return Cmmdc(b,a%b);
  }
