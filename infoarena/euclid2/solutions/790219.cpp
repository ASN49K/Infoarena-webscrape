#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long int a,b,c,aux;
int main()
{int nr;
 f>>nr;
 while(nr>0)
	{nr--;
	 f>>a>>b;
	 while(b!=0)
		 {c=a%b;
		  a=b;
		  b=c;}
	 g<<a<<'\n';
	}
 g<<12%42;
 f.close();
 g.close();
 return 0;
}

