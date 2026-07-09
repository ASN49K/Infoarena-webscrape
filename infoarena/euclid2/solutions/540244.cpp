#include<fstream>
using namespace std;
unsigned long n,p,i,s;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(i=1;i<=t;i++)
f>>a;f>>b;
max=1;
if(a>b) u=a; else u=b;
for(j=1;j<=u;j++)
if(a%j==0&&b%j==0&&j>max)
max=j;
g<<max<<endl;
return 0;}

