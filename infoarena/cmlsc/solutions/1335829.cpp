/* Se dau doi vectori A si B cu elemente numere naturale nenule.
Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.*/
#include<iostream>
#include<fstream>
using namespace std;
int a[10], b[10], c[10][10], raspuns[10], l=0;

int max(int a, int b)
{	if(a>b)return a;
	else if (b>a) return b;
}
int main()
{int i,j,m,n;
 ifstream f("cmlsc.in");
 ofstream g("cmlsc.out");
 f>>m>>n;
 for(int i=0;i<m;i++)f>>a[i];
 for(int j=0;i<n;i++)f>>b[j];

 for(int i=0;i<m;i++)
	 for(int j=0;i<n;i++)
		 if(a[i]==b[j])	c[i][j]= 1+ c[i-1][j-1];
		 else c[i][j]=max(c[i-1][j], c[i][j-1]);

	for ( i=m, j=n; i;)
if (a[i] == b[j]){
raspuns[++l] = a[i];
	i--; 
	j--;
}
else	if (c[i-1][j] < c[i][j-1])
j--;
else i--;
g<<l<<"\n";
for(int i=l; i; i--) g<<raspuns[i]<<" ";
 f.close();
 g.close();
 return 0;
}