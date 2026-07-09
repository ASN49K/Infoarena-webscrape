//Fisierul de intrare euclid2.in contine pe prima linie numarul T de perechi. 
//Urmatoarele T linii contin cate doua numere naturale a si b.
//In fisierul de iesire euclid2.out se vor scrie T linii. A i-a linie din acest fisier contine cel mai mare divizor comun 
//al numerelor din perechea de pe linia i+1 din fisierul de intrare.

#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a,int b)
{
	int r;
	if(b==0) return a;
	return cmmdc(b,a%b);
	
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int T,a,b,i;
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<endl;
	}
	f.close();
	g.close();
	return 0;
}
