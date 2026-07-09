#include <fstream>

int cmmdc(int x,int y)
{
int r=x%y;
while(r!=0)
{x=y;
 y=r;
 r=x%y;
 }
return y;
}

void main()
{
ifstream f;f.open("euclid2.in");ofstream g;g.open("euclid2.out");
int aux,n,a,b;
f>>n;
while(n!=0)
{
f>>a;
f>>b;
if(b>a) g<<cmmdc(b,a)<<"\n";
else g<<cmmdc(a,b)<<"\n";
n--;
}
f.close();
g.close();
}
