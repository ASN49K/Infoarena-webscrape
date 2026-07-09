#include <iostream>
#include <fstream>
using namespace std;
int mat[1025][1025],na, nb , k;
int a[1025], b[1025], sc[100];
int maxim(int x, int y)
{
	if(x>y)
		return x;
	else
		return y;
}
int main()
{
	int i, j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&na,&nb);
	for(i=1;i<=na;++i)scanf("%d",a+i);
	for(j=1;j<=nb;++j)scanf("%d",b+j);
	for(i=1; i<=na; i++)
		for(j=1; j<=nb; j++)
			if(a[i]==b[j])
				mat[i][j] = 1 + mat[i-1][j-1];
			else
				mat[i][j] = maxim(mat[i-1][j], mat[i][j-1]);
	i = na; j = nb;
	while(mat[i][j])
	{
		if(a[i] == b[j])
		{
			sc[++k] = a[i];
			i--; j--;
		}
		else
		{
			if(mat[i-1][j]==mat[i][j])
				i--;
			else
				j--;
		}
	}
	printf("%d\n",k);
	for(i=k; i>1; i--)
		printf("%d ",sc[i]);
    printf("%d\n",sc[1]);
    return 0;
}
