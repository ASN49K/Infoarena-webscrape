#include<fstream>
using namespace std;
int main()
{int a,b,r,t,r,i;
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
	 if (a==1)
		fout<<0;
	 else
		fout<<a<<endl;
	}
}