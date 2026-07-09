#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{if(b==0)
	return a;
else
	return cmmdc(b,a%b);
}
void parc(int n)
{int a,b;
for(int i=1;i<=n;i++)
	{f>>a>>b;
	 g<<cmmdc(a,b)<<"\n";
	}
}
int main()
{int n;
f>>n;
parc(n);
return 0;
}
