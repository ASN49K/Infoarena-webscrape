#include<fstream>
using namespace std;
int i,t,k,a,b;

int cmmdc(int a)
{ int c,n;
	while(b)
	{c=b;
     b=a%b;
     a=c;
    }
 return a; }

 int main ()
 { ifstream f("euclid2.in");
   ofstream g("euclid2.out");
   f>>t;
   for(i=1;i<=t;i++)
   { f>>a;
     f>>b;
     k=cmmdc(a);
     g<<k<<"\n";}
     return 0; }
