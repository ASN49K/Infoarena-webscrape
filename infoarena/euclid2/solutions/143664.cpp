#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long cmmdc(long a,long b)
 {int c;
   while (b)
    {c=a%b;
     a=b;
     b=c;
    }
  return a;
 }
int main()
{
long a,b;
f>>a>>b;
g<<cmmdc(a,b);
return 0;
}
