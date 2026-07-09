#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,i;
int euclid2 (int a,int b)
{while (a!=b)
	if (a>b)
		a-=b;
	else
		b-=a;
return a;}
int main()
{f>>t;
for (i=1;i<=t;i++){
	f>>a>>b;
	g<<euclid2(a,b)<<'\n';}
f.close();
g.close();
return 0;}
	