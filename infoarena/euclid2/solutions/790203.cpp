#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long int a,b;
int main()
{int nr;
 f>>nr;
 while(nr>0)
	{nr--;
	 f>>a>>b;
	 while(a!=b)
		if(a>b) a=a-b;
	    else b=b-a;
	 g<<a<<'\n';
}
 f.close();
 g.close();
 return 0;
}

