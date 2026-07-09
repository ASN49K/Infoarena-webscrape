#include<iostream>
#include<fstream>
using namespace std;
int main()
{long T,a,b,c;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
f>>T;
	while(f>>a>>b)
	{while(b)
	{c=a%b;
	a=b;
	b=c;}
	g<<a<<endl;}	
  g.close();
}
