#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,i,n,c,m,x;
int main ()
{f>>n;
for(i=1; i<=n; i++)
	f>>a;
    f>>b;
	
a=m;
b=x;
c=m%x;
while(c>0) {m=x;
			x=c;
			c=m%x;
			}
g<<b<<"\n";
g.close();
return 0;
}
