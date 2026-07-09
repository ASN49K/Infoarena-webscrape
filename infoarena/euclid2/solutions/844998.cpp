#include<fstream>
using namespace std;
long int i,t,k,a[100000],b[100000],n,div;


int cmmdc(int div)
{ int c,n;
	for(c=n;c>=1;c--)
{ if(a[i]%c==0&&b[i]%c==0) { div=c; c=0;} }
 return div; }

 int main ()
 { ifstream f("euclid2.in");
   ofstream g("euclid2.out");
   f>>t;
   for(i=1;i<=t;i++)
   { f>>a[i];
     f>>b[i]; }
   for(i=1;i<=t;i++)
   { if(a[i]<b[i]) n=a[i];
     else n=b[i];
     k=cmmdc(div);
     g<<k<<"\n";}
     return 0; }
