#include<fstream>
using namespace std;
long int a,b,cmmdc;
int main ()
{
ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>t;
for (i=1;i<=t;i++)
{in>>a>>b;
while (a!=b)
{if (a>b) a=a-b;
 if (b>a) b=b-a;
 cmmdc=a; }}
out<<cmmdc;
return 0 ;
}