#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,i;
int euclid(int x, int y)
{int r;
 if(y==0) return x;
 r=x%y;
 while(r)
	 {x=y; y=r; r=x%y;}
 return y;	 
}
int main()
{f>>t;
 for(i=1;i<=t;i++) {f>>a>>b; g<<euclid(a,b)<<'\n';}
 g.close();
 return 0;
}
