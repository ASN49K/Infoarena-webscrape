#include<cstdio>
using namespace std;

int maxim (int x, int y)
{
	if(x>y)
		return x;
	else
		return y;
}

int main ()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int na, nb, a[1026], b[1026], best[126][126], i, j, t[1026],q=-1;
	scanf("%d%d",&na,&nb);
	for(i=1;i<=na;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=nb;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=na;i++){
		for(j=1;j<=nb;j++){
			if(a[i]==b[j])
				best[i][j]=best[i-1][j-1]+1;
			else
				best[i][j]=maxim(best[i-1][j],best[i][j-1]);}}
	i=na;
	j=nb;
	printf("%d\n",best[na][nb]);
	while(best[i][j]!=0){
		if(best[i][j]==best[i-1][j])
				i--;
		else{
			if(best[i][j]==best[i][j-1])
				j--;
			else{
				if(best[i-1][j-1]+1==best[i][j]){
					t[++q]=a[i];
					i--;
					j--;}}}}
	for(i=q;i>=0;i--)
		printf("%d ",t[i]);
	return 0;
}
