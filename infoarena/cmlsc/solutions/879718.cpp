#include<fstream>
using namespace std;
int main()
	{unsigned int n,i,m,a[1024],b[1024],c[1024],nc=0,j,k;
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
				c[nc++]=b[j];
		}
	 fout<<nc<<'\n';
	 for(k=0;k<nc;k++)
		 fout<<c[k]<<" ";
	 return 0;
	}
