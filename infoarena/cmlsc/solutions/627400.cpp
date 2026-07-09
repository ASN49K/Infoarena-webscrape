#include<cstdio>
int n, m, a[1100], b[1100], i, j, nr, v[1100];
int main()
{ freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  
  scanf("%d %d", &m, &n);
  for(i=1; i<=m; i++) scanf("%d ", &a[i]);
  for(i=1; i<=n; i++) scanf("%d ", &b[i]);
  
  for(i=1; i<=m; i++)
	for(j=1; j<=n; j++)
		if(a[i]==b[j]) { nr++;
						 v[nr]=a[i];
		                 //b[j]=-1;
		               }	
  printf("%d\n", nr);
  for(i=1; i<=nr; i++) printf("%d ", v[i]);
  
  return 0;
}
