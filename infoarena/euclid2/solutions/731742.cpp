#include <fstream>
using namespace std;
int main ()
{
long a,b,r,t;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
fin>>t;
while (t)
{
fin>>a>>b;
while (b)
{
r=a%b;
a=b;
b=r;
}
fout<<a<<"\n";
t--;
}
fin.close();
fout.close();
return 0;
}