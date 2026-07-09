//Fisierul de intrare euclid2.in contine pe prima linie numarul T de perechi. 
//Urmatoarele T linii contin cate doua numere naturale a si b.
//In fisierul de iesire euclid2.out se vor scrie T linii. A i-a linie din acest fisier contine cel mai mare divizor comun 
//al numerelor din perechea de pe linia i+1 din fisierul de intrare.
#include <fstream>
using namespace std;
 
int T, A, B;
 
int gcd(int a, int b)
{
int r;
if(b==0)
	return a;
do
{
	r=a%b;
	a=b;
	b=r;
}
while(r);
return a;
}
 
int main(void)
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
 
f>>T;
for (; T; --T)
{
f>>A>>B;
g<< gcd(A, B)<<'\n';
}       
f.close();
g.close();
return 0;
}
