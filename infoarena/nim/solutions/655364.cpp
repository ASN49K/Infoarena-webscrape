#include<fstream>
using namespace std;
ifstream f("nim.in"); ofstream g("nim.out");
int main()
{int n,t,s,x;
 f>>t;
 while(t--)
	{f>>n; s=0;
	 while(n--) {f>>x; s=s^x;}
	 if(s) g<<"DA\n"; else g<<"NU\n";
	}
 g.close(); return 0;
}
