#include<fstream>
using namespace std;
int a,b,r,t,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{ f>>t;
for(i=1;i<=t;i++)
    { f>>a>>b;
	if(a==b)
	g<<a<<'\n';
   else
	if(a==0)
		g<<b<<'\n';
		else
			if(b==0)
				g<<a<<'\n';
			else
				if(a>b)
				  { r=1;
				  while(r!=0) 
				  { r=a%b;
				  a=b;
				  b=r; }
				  g<<a<<'\n'; }
				else
				  { r=1;
				  while(r!=0)
				    { r=b%a;
				    b=a;
				    a=r; }
					g<<b<<'\n'; } }
	              f.close();
				  g.close();
				  return 0; }
