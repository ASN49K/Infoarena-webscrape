#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
	if(a==b) return a;
	else if(a>b) return cmmdc(a-b,b);
	else return cmmdc(a,b-a);
}
int main()
{
	int n,a,b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	while(n!=0)
	{
		f>>a>>b;
		cout<<cmmdc(a,b)<<endl;
		n--;
	}
	f.close();
	g.close();
	return 0;
}