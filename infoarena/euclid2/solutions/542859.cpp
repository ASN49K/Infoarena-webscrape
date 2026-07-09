#include <fstream>

using namespace std;

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

int gcd(int a,int b)
{
	if(b == 0)
		return a;
	else return gcd(b, a%b);
}
int main()
{
	int n,a,b;

	ifstream fin(FIN);
	ofstream fout(FOUT);
	fin >> n;
	
	for(int i = 0; i < n; ++i)
		{ 
			fin >> a >> b;
			fout <<  gcd(a,b)  <<  endl;
		}
		
	return 0;
}