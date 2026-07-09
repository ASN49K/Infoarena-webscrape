//cel mai lung subsir comun
#include<cstdio>
#define MAXn 1030
using namespace std;
int i,j,n,m,lg,a[MAXn],b[MAXn],mat[MAXn][MAXn],sc[MAXn];
int maxim(int x ,int y )
{
	if(x > y)
		return x;
		else
		return y;
}
int main ()
{
	freopen("cmlsc.in", "r",stdin);
	freopen("cmlsc.out", "w",stdout);
	scanf("%d %d", &m, &n);	//citesc n si m
	for(i=1;i<=m;i++)
		scanf("%d", &a[i]);  //citire primul sir
	for(i=1;i<=n;i++)
		scanf("%d", &b[i]);		//citire al doilea sir
	for(i=1;i<=m;++i)	
		for(j=1;j<=n;++j)
			if(a[i]==b[j])	//daca sunt a[i] si b[j] sunt egale cresc nr de elemente din subsir
				mat[i][j]=mat[i-1][j-1]+1;
				else
				mat[i][j]=maxim(mat[i-1][j],mat[i][j-1]);	//altfel iau valoare maxima dintre ceilalti doi vecini
	lg=0;
	for(i = m, j = n ;i;)
		{
			if(a[i] == b[j])     
				{ 
					sc[++lg] = a[i];      //daca a[i] si b[j] sunt egale fac parte din subsir 
					--i;
					--j;
				}
				else
				if(mat[i-1][j] < mat[i][j-1])		//daca nu sunt egale ma mut cu indicii catre vecinul cu valoarea cea mai mare
					--j;
					else
					--i;
		}
	printf("%d\n", lg);
	for(i=lg;i;--i)
		printf("%d ", sc[i]);		//afisare lungime si subsir
	return 0;
}
