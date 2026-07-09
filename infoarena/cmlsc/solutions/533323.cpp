#include<cstdio>

using namespace std;

int m,n,i,j,lcs[1025][1025],x[1025],y[1025];

void rezolva(){
for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
	   if(x[i]==y[j]) lcs[i][j]=1+lcs[i-1][j-1];
   else 
	   if (lcs[i-1][j]>lcs[i][j-1]) lcs[i][j]=lcs[i-1][j];
   else lcs[i][j]=lcs[i][j-1];
}

void afiseaza_solutie_max(int i,int j){
if(lcs[i][j])
	if(x[i]==y[j])
       {
		   afiseaza_solutie_max(i-1,j-1);
		   printf("%d ", x[i]);
	   }
	else
        {
			if (lcs[i][j]==lcs[i-1][j]) 
				afiseaza_solutie_max(i-1,j);
			else if (lcs[i][j]==lcs[j][i-1]) 
			afiseaza_solutie_max(i,j-1);
		}
}


int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;i++)
		scanf("%d", &x[i]);
	for(j=1;j<=m;j++)
		scanf("%d", &y[j]);
	rezolva();
	printf("%d\n", lcs[n][m]);
	afiseaza_solutie_max(n,m);
return 0;
}