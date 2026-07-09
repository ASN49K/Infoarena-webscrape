#include <fstream>
using namespace std;

int n,a,b;

int gdc(int a, int b){
	while(a!=b)
	if(a>b)
		a-=b;
	else
		b-=a;
	return a;
}

int main(){
	fin >> n;
	for(int i=1; i<=n; ++i)
	{
		fin >> a >> b;
		gdc(a,b);
		fout << a << '\n';
	}
}