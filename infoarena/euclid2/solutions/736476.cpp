#include <fstream>
using namespace std;
int T,A,B,r;
int main(void)
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>T;
while (T)
{
T--;
fin>>A>>B;
while (B)
{
r=A%B;
A=B;
B=r;
}
fout<<A<<"\n";
}
fin.close();
fout.close();
return 0;
}