#include<fstream>
using namespace std;
long cmmdc(long d,long i)
 {long r,aux;
if(d<i){aux=d;d=i;i=aux;}
	 r=d%i;
	 while(r!=0)
	 {
		 d=i;
		 i=r;
		 r=d%i;
	 }
	 return i;
 }
 
int main()
{long a,b,n,i,j;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(j=0;j<n;j++)
	 {
	  f>>a>>b;
	   g<<cmmdc(a,b)<<"\n";
	 }
f.close();g.close();
return 0;}
