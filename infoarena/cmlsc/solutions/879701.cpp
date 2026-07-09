#include<fstream>
using namespace std;
int main()
	{unsigned int n,i,m,a[100],b[100],c[100],nc=0,j;
	 ifstream fin("cmlsc.in");
	 ofstream fout("cmlsc.out");
	 fin>>n>>m;
	 for(i=0;i<n;i++)
		 fin>>a[i];
	 for(j=0;j<m;j++)
		 fin>>b[j];
	 for (i=0;i<n;i++)
		{for(j=0;j<m;j++)
			 if (a[i]==b[j])
				c[nc++]=a[i];
		}
	 fout<<nc<<'\n';
	 for(i=0;i<nc;i++)
		 fout<<c[i]<<" ";
	}