/* Dandu-se T perechi de numere naturale (a, b), sa se calculeze cel mai mare divizor comun al numerelor din fiecare pereche in parte.*/

#include<iostream.h>
#include<fstream.h>
int cmmdc(int a, int b)
{
	if(b==0)
		return a;
	else
		return cmmdc(b,a%b);
}
 int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int a,b,T,i;
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<endl;
	}
	return 0;
 }
