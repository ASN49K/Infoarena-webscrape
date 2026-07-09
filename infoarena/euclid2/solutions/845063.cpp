#include<fstream>
using namespace std;
int i,t,j,k,a,b,div;

int cmmdc(int div)
{ int c,n;
if(a<b) n=a;
     else n=b;
	for(c=n;c>=1;c--)
{ if(a%c==0&&b%c==0) { div=c; c=0;} }
 return div; }

 int main ()
 { ifstream f("euclid2.in");
   ofstream g("euclid2.out");
   f>>t;
   j=t;
   for(i=1;i<=t;i++)
   { f>>a;
     f>>b;
     k=cmmdc(div);
     g<<k<<"\n";}
     return 0; }
