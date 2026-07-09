#define FOR(i,a,b) for(i=a;i<=b;i++)
#define maxim(a,b) (a>b) ? a:b
#define maxLength 1024
#include<stdio.h>

unsigned DIM[maxLength][maxLength], i, j, n, m, A[maxLength], B[maxLength],sir[maxLength],length;
int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);	
	scanf("%u %u", &n, &m);
	FOR(i, 1, n)
		scanf("%u", &A[i]);
	FOR(i, 1, m)
		scanf("%u", &B[i]);
	FOR(i,1,n)
		FOR(j,1,n)
			if (A[i] == B[j])
				DIM[i][j] = DIM[i - 1][j - 1] + 1;
			else
				DIM[i][j] = maxim(DIM[i][j - 1], DIM[i - 1][j]);
			for (i = n, j = m; j;)
			if (A[i] == B[j])
			{
				sir[++length] = A[i];
				i--; j--;
			}
			else
			if (DIM[i - 1][j] > DIM[i][j - 1])
				i--;
			else
				j--;
			printf("%u\n", length);
			for (i = length; i >= 1;i--)
				printf("%u ", sir[i]);
			return 0;
}