#include<cstdio>
#include<fstream>
using namespace std;
FILE *fin=fopen("cmlsc.in","r");
FILE *fout=fopen("cmlsc.out","w");
int i,m,j,n,v1[300],v2[300],a[1026][1026],rez[300],k;
int main()
{fscanf(fin,"%d %d",&n,&m);
 for(i=1;i<=n;++i)
	 fscanf(fin,"%d",&v1[i]);
 for(i=1;i<=m;++i)
	 fscanf(fin,"%d",&v2[i]);
 for(i=1;i<=n;++i)
	 for(j=1;j<=m;++j)
		 if(v1[i]!=v2[j])
			 a[i][j]=max(a[i-1][j],a[i][j-1]);
		 else
			 a[i][j]=a[i-1][j-1]+1;
 fprintf(fout,"%d\n",a[n][m]);
 i=n;j=m;k=0;
 while(a[i][j]!=0)
	 if(v1[i]==v2[j])
		 {rez[k++]=v1[i];
		  i--;
		  j--;
		 }
	 else
		 {if(a[i-1][j]==a[i][j])
			 i--;
		  else
		     j--;
		 }
 for(i=k-1;i>=0;--i)
	 fprintf(fout,"%d ",rez[i]);
 fprintf(fout,"\n");
 return 0;
}
