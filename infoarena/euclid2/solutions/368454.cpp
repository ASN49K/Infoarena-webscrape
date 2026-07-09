#include<fstream.h>

unsigned long n,i,a,b,aux;

int main()
{
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 for(i=1;i<=n;i++)
  {
   f>>a>>b;
   while(a!=b)if(a>b){aux=a/b;aux*=b;a-=aux;}
	      else {aux=b/a;aux*=a;b-=aux;}
   g<<a<<'/n';
   }
 return 0;
 }
