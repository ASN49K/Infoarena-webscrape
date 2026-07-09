#include <cstdio>

using namespace std;

FILE * intrare = fopen("cmlsc.in","r");
FILE * iesire = fopen("cmlsc.out","w");

int n, m;
int a[2000], b[2000];
int lcs[2000][2000];
int op[1050][1050];

int mmax(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

int main()
{
  int i, j;
  fscanf(intrare,"%d %d",&n,&m);
  
  for(i = 1; i <= n; i++)
    fscanf(intrare,"%d",&a[i]);
  for(i = 1; i <= m; i++)
    fscanf(intrare,"%d",&b[i]);
  
  for(i = n; i >= 1; i--)
    for(j = m; j >= 1; j--)
      if (a[i] == b[j])
	  {
		op[i][j] = 1;
        lcs[i][j] = 1 + lcs[i+1][j+1];
	  }
      else
	  {
        lcs[i][j] = mmax(lcs[i+1][j],lcs[i][j+1]);
		if (lcs[i+1][j] > lcs[i][j+1])
			op[i][j] = 2;
		else
			op[i][j] = 3;
	  }
  
	fprintf(iesire,"%d\n",lcs[1][1]);
	i = 1;
	j = 1;
	while(i<=n &&j<=m)
		if(op[i][j] == 1)
		{
			fprintf(iesire,"%d ", a[i]);
			i++;
			j++;
		}
		else
			if(op[i][j]==3)
				j++;
			else
				i++;
  fprintf(iesire,"\n");
  fclose(iesire);
  return 0;
}
