#include<iostream>
#include<fstream>

using namespace std;

long n, a,b,i;

int verif(int a, int b)
{int c,i;
	if(a<b) c=a;
else c=b;
for(i=c; i>=1; i--)
if(a%i==0 && b%i==0) return i;
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g ("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++) {f>>a>>b; g<<verif(a,b)<<endl;}
	f.close();
	g.close();
}
	