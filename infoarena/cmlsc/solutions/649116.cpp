#include<fstream>
using namespace std;
int max(int a, int b)
	{if(a>b)return a;
     return b;
  }
int vv[1024][1024]={0};
int main()
{
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,v1[1024],v2[1024],vfin[1024],i,j,k=0,dd;
f>>n>>m;
for(i=1;i<=n;i++)f>>v1[i];
for(i=1;i<=m;i++)
	{f>>v2[i];
	 for(j=0;j<n;j++)
	   if(v2[i]==v1[j]) 
			vv[i][j]=vv[i-1][j-1]+1;
	 
	   else vv[j][j]=max(vv[i-1][j],vv[i][j-1]);
			
	}
i=n;j=m;
while(i)
	{if(v1[i]==v2[j])
	     vfin[++k]=v1[i],i--,j--;
	else if(vv[i-1][j]>vv[i][j-1])j--;
	else i--;
	}
g<<k<<endl;
for(i=k;i>0;i--)g<<vfin[i]<<" ";
f.close();
g.close();
return 0;
}