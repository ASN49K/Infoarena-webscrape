#include<iostream>
#include<fstream>
using namespace std;
/* http://www.infoarena.ro/problema/euclid2
Cerinta
Dandu-se T perechi de numere naturale (a, b), sa se calculeze cel
mai mare divizor comun al numerelor din fiecare pereche in parte.

Date de intrare
Fisierul de intrare euclid2.in contine pe prima linie numarul T de 
perechi. Urmatoarele T linii contin cate doua numere naturale a si b.

Date de iesire
In fisierul de iesire euclid2.out se vor scrie T linii. A i-a linie 
din acest fisier contine cel mai mare divizor comun al numerelor din 
perechea de pe linia i+1 din fisierul de intrare.

Restrictii
1 = T = 100 000
Pentru fiecare pereche: 2 = a, b = 2 * 10^9
*/
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	int t,i,x,y,r;
	long long a[100000],b[100000];
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>a[i];
		fin>>b[i];
	}
	for(i=1;i<=t;i++)
	{
		x=a[i];
		y=b[i];
		while(y>0)
		{
			r=x%y;
			x=y;
			y=r;
		}
		fout<<x<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
