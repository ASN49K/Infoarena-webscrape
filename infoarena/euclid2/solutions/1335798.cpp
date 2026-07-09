#include<fstream>
using namespace std;
int a,b,r;

int cmmdc2(int a, int b)
{	while(b!=0){r=a%b;
				a=b;
				b=r;
			   }
return a;
}
int main()
{int i=0,t;
 ifstream f("cmmdc2.in");
 ofstream g("cmmdc2.out");
 f>>t;
 while(i<t){	f>>a;
				f>>b;
				g<<cmmdc2(a,b)<<"\n";
				i++;
			}


 f.close();
 g.close();
 return 0;
}