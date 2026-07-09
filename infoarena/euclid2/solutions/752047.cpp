#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b)
{
int r;
r = a%b;
while(r != 0)
     {
      a=b;
      b=r;
      r=a%b;
     }
return b;
}

int main()
{
int n,i,a,b;
f>>n;
for(i=1; i<=n; i++)
    {
     f>>a>>b;
     g<<cmmdc(a,b);
    }

f.close();
g.close();
return 0;
}
