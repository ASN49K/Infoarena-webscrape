#include<iostream>
#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{
	int div;
	while (b!=0)
	{
		div=a%b;
		a=b;
		b=div;
	}
	return a;   
}
int main()
{
	ifstream intrare("euclid2.in");
	ofstream iesire("euclid2.out");
	int a,b,c,d;
	if(!intrare)
		cout<<"Eroare la deschiderea fisierului";
	else
		if(intrare)
		{
			intrare>>c;
			for(d=1;d<=c;d++)
			{
				intrare>>a;
				intrare>>b;
				iesire<<cmmdc(a,b)<<"\n";
			}
		}
		return 0;
}