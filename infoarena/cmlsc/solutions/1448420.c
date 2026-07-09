#include <stdio.h>

int main()
{
	int n, m,i;
	int A[256], B[256], C[256];
	
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	for(i = 0; i < m; i++)
	{
		scanf("%d", &B[i]);
	}
	
	int contor = 0;
	int l = 0;
	int k = 0;
	while(l < n)
	{
		for(i = k; i < m; i++)
		{
			if(A[l] == B[i + k] && i + k < m)
			{
				contor++;
				C[k] = A[l];
				k++;
				break;
			}
		}
		l++;
	}
	
	printf("%d\n", contor);
	
	for(i = 0; i < k; i++)
	{
		printf("%d ", C[i]);
	}
	
	return 0;
}	
