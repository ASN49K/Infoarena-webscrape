/*
	a[i][j] = lungimea celui mai lung subsir comun folosind primele
			 i elem din primul vector si primele j elem din al doilea vector
	a[i][j] = a[i-1][j-1] + 1  pt s[i] == t[j] //s[i] se poate adauga la cel mai lung subsir precedent, care nu foloseste s[i] sau t[j].
                       sau
              max(a[i-1][j],a[i][j-1]) //lungimea celui mai lung subsir de pana acum.
	Numerele se reconstituie dupa matrice.
*/

#include <cstdio>

const int M = 1025, N = 1025;

int s[M],t[N],m,n;
int a[M][N];

inline int max(int a, int b)
{
	return (a>b)?a:b;
}

void citire()
{
	scanf("%i%i",&m,&n);
	for (int i = 1; i <= m; ++i)
		scanf("%i",&s[i]);
	for (int j = 1; j <= n; ++j)
		scanf("%i",&t[j]);
}

void dinamica()
{
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (s[i] == t[j])
				a[i][j] = a[i-1][j-1] + 1;
			else
				a[i][j] = max(a[i-1][j],a[i][j-1]);
}

void scrie(int i, int j)
{
	if ((i == 0)||(j == 0))
		return;
	if (s[i] == t[j])
	{
		scrie(i-1,j-1);
		printf("%i ",s[i]);
	}
	else
		if (a[i-1][j] > a[i][j-1])
			scrie(i-1,j);
		else
			scrie(i,j-1);
}

void afisare()
{
	printf("%i\n",a[m][n]);
	scrie(m,n);
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	citire();
	dinamica();
	afisare();
	return 0;
}
