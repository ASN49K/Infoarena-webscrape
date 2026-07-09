#include<fstream>
using namespace std;
int cmmdc(int a, int b)
	{int r;
			while(b!=0)
			{r=a%b;
		     a=b;
			 b=r;
			}
	return a;
	}
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b;
f>>n;
while(n){f>>a>>b; g<<cmmdc(a,b)<<"\n";n--;}
f.close();
g.close();
return 0;
}