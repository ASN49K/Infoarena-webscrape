#include<fstream.h>
#include<math.h>
using namespace std;
long a, b, n;
ifstream f("euclid2.in");
ofstream g("euclid2.out");


int cmmdc(int x, int y)
{
if(!y) return x;
return cmmdc(y, x%y); 
}  

void citire()
{
f>>n;
for(int i=1;i<=n;i++)
{
f>>a>>b;
g<<cmmdc(a, b)<<endl;
}
}





int main()
{
citire();
return 0;
}