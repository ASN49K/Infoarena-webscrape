#include<fstream>
using namespace std;
int main()
{int a[200000],i,t,n1,n2,r;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>t;
for(i=1;i<t+t;i+=2)
	{fin>>a[i];
	 fin>>a[i+1];
	 n1=a[i];
	 n2=a[i+1];
	 do{r=n1%n2;
	 n1=n2;
	 n2=r;
	 }while(r!=0);
	 fout<<n1<<'\n';
	}
return 0;
}