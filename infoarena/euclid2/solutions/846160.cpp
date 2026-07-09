#include<fstream>
using namespace std;
ifstream f("euclid2.in"); ofstream g("euclid2.out");
int T,a,b,c,d,i;
inline int euclid( int x, int y)
{int r;
 if(y == 0) return x;
 while(y)
  {r=x%y; x=y; y=r;}
 return x;
}
int main()
{f>>T;
 while(T)
	 {f>>a>>b;
	  g<<euclid(a,b)<<"\n";
	  T--;
	 }
 g.close(); return 0;
}
