#include<fstream>
using namespace std;
int max(int a, int b, int c)
	{if(a>b&&a>c)return a;
     if(b>c&&b>a)return b;
	 return c;
  }
int main()
{
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,v1[1024],vant[1024]={0},vmeu[1024]={0},vfin[1024],i,j,k=0,dd;
f>>n>>m;
for(i=1;i<=n;i++)f>>v1[i];
for(i=1;i<=m;i++)
	{f>>dd;
	 for(j=0;j<n;j++)
	   if(dd==v1[j]) 
			{vmeu[j]=max(vant[j-1]+1,vmeu[j-1],vant[j]);
			 if(vmeu[j]==vant[j-1]+1) vfin[++k]=dd;
	         }
	   else vmeu[j]=max(vant[j-1],vmeu[j-1],vant[j]);
	for(j=0;j<=n;j++)
	   vant[i]=vmeu[i];
		
	}
g<<k<<endl;
for(i=0;i<k;i++)g<<vfin[i+1]<<" ";
f.close();
g.close();
return 0;
}