#include<fstream>
using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int N,a,b,i,k;

int GCDivisor(int a, int b)
{
	while(b)k=b,b=a%b,a=k;
	return a;
}

int main()
{
	fi >> N;
	for(i=1; i<=N; i++) fi >> a >> b, fo << GCDivisor(a,b) << '\n';
}

