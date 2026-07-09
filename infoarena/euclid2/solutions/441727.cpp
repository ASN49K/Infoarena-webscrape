#include<fstream>
using namespace std;
long cmmdc(long d,long i)
 {long r,aux;
if(d<i){aux=d;d=i;i=r;}
	 r=d%i;
	 while(r!=0)
	 {
		 d=i;
		 i=r;
		 r=d%i;
	 }
	 return i;
 }
 long a,b,n,i,x;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=0;i<n;i++)
	 {
	  f>>a>>b;
	   x=cmmdc(a,b);
	   g<<x<<"\n";
	 }
f.close();g.close();
return 0;}
