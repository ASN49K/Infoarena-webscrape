#include <fstream>
using namespace std;
int t,a,b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int gdc(int a, int b){
	if(a==0) return b;
	if(b==0) return a;

	while(a!=b)
	if(a>b)
		a-=b;
	else
		b-=a;
	return a;
}

int main(){
	fin >> t;
	for(int i=1; i<=t; ++i)
	{
		fin >> a >> b;
		fout << gdc(a,b) << '\n';
	}
}
