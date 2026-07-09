#include<stdio.h>
#define infile "cmlsc.in"
#define outfile "cmlsc.out"
#define lmax 1100
int x[lmax][lmax]; //matricea in care vom face dinamica
unsigned char a[lmax], b[lmax];
int m,n; //lungimile celor doua siruri

int max(int a, int b)
	{ if(a>b) return a; return b; }

void citire(unsigned char a[lmax], unsigned char b[lmax], int *m, int *n)
	{
	int i;
	scanf("%d %d\n",m,n); //lungimile celor doua siruri
	for(i=1;i<=*m;i++) scanf("%d",&a[i]); //primul sir
	for(i=1;i<=*n;i++) scanf("%d",&b[i]); //al doilea sir
	}

void dinamica(int x[lmax][lmax], unsigned char a[lmax], unsigned char b[lmax], int m, int n)
	{
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j]) x[i][j]=x[i-1][j-1]+1; //are lungimea cu 1 mai mare, deoarece au aceleasi caractere
			else x[i][j]=max(x[i-1][j],x[i][j-1]); //nu au acelasi caracter....deci se pastreaza cea mai mare lungime gasita pana acum
	}

int afisare_subsir(int x[lmax][lmax], unsigned char a[lmax], int i, int j)
	{
	if(!i||!j) return 0; //nu mai are niciun element
	if(x[i][j]==x[i-1][j]) afisare_subsir(x,a,i-1,j); //vine din partea stanga
	else if(x[i][j]==x[i][j-1]) afisare_subsir(x,a,i,j-1); //vine de deasupra
	else if(x[i-1][j-1]+1==x[i][j])
		{ //inseamna ca elementele celor doua siruri au fost egale :P (a[i]==b[j])
		afisare_subsir(x,a,i-1,j-1); //afsem restul subsirului
		printf("%d ",a[i]); //afisem elementul din sir
		}
	return 0;
	}

int main()
{
freopen(infile,"r",stdin);
freopen(outfile,"w",stdout);

citire(a,b,&m,&n); //citim
dinamica(x,a,b,m,n); //facem matricea pt cel mai lung subsir comun (prog. dinamica)

printf("%d\n",x[m][n]); //afisem lungimea celui mai lung subsir comun
afisare_subsir(x,a,m,n); //afisem subsirul

fclose(stdin);
fclose(stdout);
return 0;
}