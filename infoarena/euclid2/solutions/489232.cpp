#include<fstream>
using namespace std;
int n,a,b;
int cmmdc(int a,int b)
{
	 if(a>b)
		 return cmmdc(a-b,b);
	 if(a<b)
		 return cmmdc(b-a,a);
	 else
		 return a;
}
int main()
{
	 ifstream f("euclid2.in");
	 ofstream g("euclid2.out");
	 f>>n;
	 for(int i=1;i<=n;i++)
	 {
		 f>>a>>b;
if(a>b)
g<<cmmdc(a,b)<<"\n";
else
	g<<cmmdc(b,a)<<"\n";
	 }
	 f.close();
	 g.close();
	 return 0;
}
