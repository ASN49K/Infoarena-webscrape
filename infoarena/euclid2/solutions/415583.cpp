#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,b;
int main()
{ f>>a>>b;
  while(a!=b)   if(a>b)a-=b;
			    else b-=a;
			
  g<<a;
  f.close();
  g.close();
  return 0;
}