#include <cstdio>
#include <vector>

using namespace std;

int l[1025][1025];


int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	int n, m, i, j;
	scanf("%d%d", &n, &m);
	vector<int> a(n+1), b(m+1);
	for(i=1; i<=n; ++i)
		scanf("%d", &a[i]);
	for(i=1; i<=m; ++i)
		scanf("%d", &b[i]);

	for(i=1; i<=n; ++i)
		for(j=1; j<=m; ++j)
		{
			if(a[i] == b[j])
				l[i][j]= 1+l[i-1][j-1];
			else if(l[i-1][j] > l[i][j-1])
					l[i][j] = l[i-1][j];
				 else
					l[i][j] = l[i][j-1];
		}

    vector<int> rez;
    --i;
    --j;

	while(i && j)
	{
		if(a[i] == b[j])
		{
			rez.push_back(a[i]);
			--i;
			--j;
		}
		else if(l[i][j-1] < l[i-1][j])
				--i;
			 else
				--j;
	}

	printf("%d\n", rez.size());
	for(i=rez.size()-1; i>=0; --i)
		printf("%d ", rez[i]);
    return 0;
}
