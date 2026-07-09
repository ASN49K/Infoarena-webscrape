#include<fstream>
using namespace std;
int main()
{int a,b,r,n,r;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for (i=0;i<n;i++)
	{fin>>a; fin>>b;
	while(b)
		{r=a%b;
		 a=b;
		 b=r;
		}
	 if (a==1)
		fout<<0;
	 else
		fout<<a;
	}
}