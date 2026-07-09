#include<iostream>
#include<fstream>
using namespace std;
int alg(int a,int b)
{
	if(!b)
		return a;
	return alg(b,a%b);
}
int main()
{
	int a,b,t;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	while(t)
	{
		f>>a>>b;
		g<<alg(a,b)<<endl;
		t--;
	}
}