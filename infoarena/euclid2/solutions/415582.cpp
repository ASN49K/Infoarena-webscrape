#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,b,c;
int main()
{ f>>a>>b;
  while(b) { a=a%b;
			 c=b;
			 b=a;
			 a=c;
			}
  g<<a;
  f.close();
  g.close();
  return 0;
}