#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long c,a,b;
int t,i;
int main()
{ f>>t;
	for(i=1;i<=t;i++) { 
  f>>a>>b;
  while(b) { a=a%b;
             c=b;
			 b=a;
			 a=c;
		   }
  g<<a<<'\n';
					  }
  f.close();
  g.close();
  return 0;
}