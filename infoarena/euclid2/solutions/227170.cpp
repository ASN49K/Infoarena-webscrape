#include <fstream>
using namespace std;
ifstream f1 ("euclid2.in);
ofstream f2 ("euclid2.out");
int main()
{
long n,a,b,i;
f1>>n;
for (i=1; i<=n; i++)
 {f1>>a>>b;
  while (a!=b) 
      {if a>b) a=a-b; 
          else b=b-a;}
  f2<<a;}
f1.close();
f2.close();}