#include<fstream>
using namespace std;
int main()
{int T,i,a,b,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
for(i=1;i<=T;i++)
{f>>a>>b;
if(a%b==0)
	g<<b;
else
	{r=a%b;
	b=b%(a%b);
	 while(b)
 {a=r%b;
 r=b;
 b=a;}
 g<<endl<<r<<endl;}}
}