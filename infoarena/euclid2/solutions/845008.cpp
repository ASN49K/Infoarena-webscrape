
#include<fstream>
#include<algorithm>
using namespace std;
int i,t,k,a[100000],b[100000],divig;

int cmmdc(int divig)
{ int c,n;
if(a[i]<b[i]) n=a[i];
     else n=b[i];
	for(c=n;c>=1;c--)
{ if(a[i]%c==0&&b[i]%c==0) { divig=c; c=0;} }
 return divig; }

 int main ()
 { ifstream f("euclid2.in");
   ofstream g("euclid2.out");
   f>>t;
   for(i=1;i<=t;i++)
   { f>>a[i];
     f>>b[i]; }
   for(i=1;i<=t;i++)
   {
     k=cmmdc(divig);
     g<<k<<"\n";}
     return 0; }
