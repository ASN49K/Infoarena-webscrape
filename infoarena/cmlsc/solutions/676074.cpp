#include<cstdio>
using namespace std;
int i,n,m;
int main()
{   
	int v[256],a[256],l[100][100],q[256];
	int j,r=1,k=0;
	FILE* f=fopen("cmlsc.in","r");
	FILE* g=fopen("cmlsc.out","w");
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&m);
	for(i=1;i<=n;++i)
		fscanf(f,"%d",&a[i]);
	for(i=1;i<=m;++i)
		fscanf(f,"%d",&v[i]);
	for(i=0;i<=n;++i)
		for(j=0;j<=m;++j)
			l[i][j]=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(a[i]==v[j])
				{
					l[i][j]=l[i-1][j-1]+1;
			    }
			else
			{
				if(l[i-1][j]>l[i][j-1])
					l[i][j]=l[i-1][j];
				else
					l[i][j]=l[i][j-1];
			} 
			do
			{
			if(l[n][m]!=l[n-1][m]&&l[n][m]!=l[n][m-1])
				{
					q[r]=a[n];
					k++;
					r++;
					n--;
					m--;
			}
			else
				if(l[n][m]==l[n-1][m])
					--n;
				else
					if(l[n][m]==l[n][m-1])
						--m;
			}
			while (n!=0&&m!=0);
			r--;
			fprintf(g,"%d \n",k);
			for(i=r;i>=1;--i)
				fprintf(g,"%d ",q[i]);
}
				
			

