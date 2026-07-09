#include<fstream.h>

unsigned long n,i,a,b;

int main()
{
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 for(i=1;i<=n;i++)
  {
   f>>a>>b;
   while(a!=b)if(a>b)a=(a-(a/b)*b);
	      else b=(b-(b/a)*a);
   g<<a<<'/n';
   }
 return 0;
 }
