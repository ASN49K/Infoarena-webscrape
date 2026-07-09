#include<iostream>
#include<fstream>
using namespace std;

int main ()
{
	int i,j,t,n,s,x;
	ifstream f("nim.in");
	ofstream g("nim.out");
	f>>t;
	for(i=1;i<=t;i++) {
		f>>n;
		s=0;
		for(j=1;j<=n;j++) {
			f>>x;
			s=(s^x);
		}
		if(s) 
			g<<"DA";
		else g<<"NU";
		g<<'\n';
	}
	f.close();
	g.close();
	return 0;
}
