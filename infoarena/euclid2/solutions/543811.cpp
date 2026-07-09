#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{int r=1;
if(a<b)
	r=a,a=b,b=r;
while(r!=0)
	{r=a%b;
	a=b;
	b=r;
	}
return a;
}
int main()
{int i,t,a,b;
ifstream in("euclid2.in");
in>>t;
ofstream out("euclid2.out");
for(i=0;i<t;i++)
	{in>>a>>b;
	out<<cmmdc(a,b)<<'\n';}
in.close();
out.close();
return 0;
}
