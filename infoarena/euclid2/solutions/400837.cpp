#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int r,i,b;
int euclid (int a, int b)
{
while (b)
{ r=a%b;
  a=b;
  b=r;
}
return b;
}

int main()
{ int n, x[1000],y[1000];
f>>n;
for (i=1;i<=n;i++)
f>>x[i];
f>>y[i];
euclid(x[i],y[i]);
g<<b;
}
