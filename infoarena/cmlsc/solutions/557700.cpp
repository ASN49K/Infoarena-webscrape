#include<cstdio>
#define maxim 1024
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define max(a, b) ((a > b) ? a : b)
int n,m,a[maxim],b[maxim],t[maxim][maxim],sir[maxim],bst;

void read()
{	int i;
	freopen("cmlsc.in","r",stdin);
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,m) scanf("%d",&b[i]);
	fclose(stdin);
}
void solve()
{ freopen("cmlsc.out","w", stdout);
	int i,j;
	FOR(i,1,n) 
		FOR(j,1,m)
			if(a[i]==b[j])	t[i][j] = t[i-1][j-1] + 1;
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
 for (i = n, j = m; i; )
        if (a[i]==b[j])
            sir[++bst] = a[i], --i, --j;
        else if (t[i-1][j] < t[i][j-1])
            --j;
        else
            --i;
 printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);
fclose(stdout);
}


	

int main()
{
	read();
	solve();
	return 0;
}