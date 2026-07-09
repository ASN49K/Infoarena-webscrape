#include<fstream>
using namespace std;
int main()
{int n,i,n1,n2,s=0,j,r,a[50];
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for(i=1;i<=n+n;i++)
	fin>>a[i];
for(i=1;i<=n+n;i++)
	{n1=a[i];
	 n2=a[i+1];
	 do{r=n1%n2;
	 n1=n2;
	 n2=r;
	}while(r!=0);
	fout<<n1<<'\n';
	i++;
	}
return 0;
}
