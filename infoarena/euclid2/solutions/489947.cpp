#include<iostream>
#include<fstream>

using namespace std;

int n, a, b;
int cmmdc(int a, int b)
{
	if(!b) return a;
	else
		return cmmdc(b,a%b);
}

int main()
{
	int i;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	
	f>>n;
	
	for(i=0;i<n;i++)
	{
		f>>a>>b;
		if(a<b)
			g<<cmmdc(b,a)<<endl;
		else
			g<<cmmdc(a,b)<<endl;
	}
	
	f.close();
	g.close();
	return 0;
}

