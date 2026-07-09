#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x,y,n;
int euclid ( int a , int b )
 {if(b==0) return a;
  return euclid (b,a%b);
 }
int main()
 {f>>n;
  for(int i=1;i<=n;++i)
	  {f>>x>>y; 
	   g<<euclid(x,y)<<"\n";
	  }	   
  f.close(); g.close(); return 0;
 } 
 