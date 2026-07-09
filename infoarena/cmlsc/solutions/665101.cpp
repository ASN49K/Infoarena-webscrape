#include<cstdio>

using namespace std;

int a[1025],b[1025],m,n,i,j,lcs[1025][1025],max;

void rezolva()
{
	for(i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i]==b[j]) lcs[i][j]=1+lcs[i-1][j-1];
			else
				if (lcs[i-1][j]>lcs[i][j-1]) lcs[i][j]=lcs[i-1][j];
				else lcs[i][j]=lcs[i][j-1];
	printf("%d\n",lcs[m][n]);
}

void afiseaza_solutie_max(int i,int j)
{
	if(lcs[i][j])
		if(a[i]==b[j])
		{
			afiseaza_solutie_max(i-1,j-1);
			printf("%d ",a[i]);
		}
		else
        {
			if (lcs[i][j]==lcs[i-1][j]) 
				afiseaza_solutie_max(i-1,j);
			else 
				if (lcs[i][j]==lcs[i][j-1]) 
					afiseaza_solutie_max(i,j-1);
     }
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(j=1;j<=n;j++)
		scanf("%d",&b[j]);
	rezolva();
	afiseaza_solutie_max(m,n);
	
	return 0;
}
