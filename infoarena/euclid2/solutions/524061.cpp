#include<fstream.h>
ifstream f("euclid2.in"); 
ofstream g("euclid2.out");
int a,b,r,i,T;
int main()
{f>>T;
 while(T)
	 {f>>a>>b;
	  if(b==0) g<<a<<'\n';
	  while(b)
	  {r=a%b; a=b; b=r;}
	  g<<a<<"\n";
	  T--;
	 }
 g.close(); return 0;
}
