#include<cstdio>
using namespace std;

int maxim (int x, int y){
	if(x>y)	return x;
	else	return y;
}

int n, m, a[1026], b[1026], matrix[1026][1026], i, j, t[1026],q=-1;

int main ()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i]==b[j])
				matrix[i][j]=matrix[i-1][j-1]+1;
			else
				matrix[i][j]=maxim(matrix[i-1][j],matrix[i][j-1]);}}
	i=n;
	j=m;
	printf("%d\n",matrix[i][j]);
	while(matrix[i][j]!=0)
	{
		if(matrix[i][j]==matrix[i-1][j])
				i--;
		else
		{
			if(matrix[i][j]==matrix[i][j-1])
				j--;
			else
			{
				if(matrix[i-1][j-1]+1==matrix[i][j])
				{
					t[++q]=a[i];
					i--;
					j--;
				}
			}
		}
	}
	for(i=q;i>=0;i--)
		printf("%d ",t[i]);
	return 0;
}