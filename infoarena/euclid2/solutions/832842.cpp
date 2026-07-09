#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
inline int euclid(int&x,int&y,int a,int b)
{

if(!b)
{
x=1;

y=0;
return a;
}
int x0,y0,d;
d=euclid(x0,y0,b,a%b);
x=y0;
y=x0-(a/b)*y0;
return d;
}
int main()
{
int t,a,b,c,d,x,y;
f>>t;
while(t--)
{
f>>a>>b>>c;
d=euclid(x,y,a,b);
if(c%d==0)
g<<x*(c/d)<<' '<<y*(c/d)<<'\n';
else
g<<"0 0\n";
}
f.close();
g.close();
return 0;
}
