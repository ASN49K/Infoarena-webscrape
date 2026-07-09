#include<fstream>
using namespace std;
int main()
{int a,b,r,t,i;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>t;
for (i=1;i<=t;i++)
	{fin>>a; fin>>b;
	 while(b)
		{r=a%b;
		 a=b;
		 b=r;
		}
	 fout<<a<<endl;
	}
}