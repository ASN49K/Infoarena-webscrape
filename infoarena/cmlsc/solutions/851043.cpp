#include<cstdio>

FILE *fin=fopen("cmlsc.in","r");
FILE *fout=fopen("cmlsc.out","w");

using namespace std;

int n,m,v[1030],a[1030];
int DP[1030][1030];

void generare()
{
	int i;
	fscanf(fin,"%d%d",&n,&m);
	for(i=1;i<=n;i++)
		fscanf(fin,"%d",&v[i]);
	for(i=1;i<=m;i++)
		fscanf(fin,"%d",&a[i]);
	
}
void rezolvare()
{
	int i,j;
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(v[i]==a[j])
			{
				if(i==0||j==0)
					DP[i][j]=1;
				else
					DP[i][j]=1+DP[i-1][j-1];
					
			}
			else
				if(i==0&&j==0)
					DP[i][j]=0;
				else
					if(i==0)
						DP[i][j]=DP[i-1][j];
					else
						if(j==0)
							DP[i][j]=DP[i][j-1];
						else
							if(DP[i-1][j]>DP[i][j-1])
							DP[i][j]=DP[i-1][j];
							else
								DP[i][j]=DP[i][j-1];
						
	int aux[1030];
	int contor;
	
	contor=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(DP[i][j]!=0&&v[i]==a[j])
			{
				contor++;
				aux[contor]=v[i];
			}
			
	fprintf(fout,"%d\n",contor);
    for(i=1;i<=contor;i++)
       fprintf(fout,"%d ",aux[i]);	
	
}

int main()
{
	generare();
	rezolvare();

	return 0;
}