#include<fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int n,m,c,i,j,s;

int main()
{
f>>n;
for(i=1; i<=n; i++)
{
f>>m;
s=0;
for(j=1; j<=m; j++)
  {f>>c;
   s=s^c;}
if(s==0)
g<<"NU"<<endl;
else
g<<"DA"<<endl;

}
f.close();
g.close();
return 0;}
