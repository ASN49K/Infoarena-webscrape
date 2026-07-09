#include<fstream>
using namespace std;
int i,t,k,a[10000],b[10000],div;


int cmmdc(int div)
{ int c,n;
if(a[i]<b[i]) n=a[i];
     else n=b[i];
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
   {
     k=cmmdc(div);
     g<<k<<"\n";}
     return 0; }
