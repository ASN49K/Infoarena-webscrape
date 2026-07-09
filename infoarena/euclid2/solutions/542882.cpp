#include <fstream>

using namespace std;

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

/*
int gcd(int a,int b)
{
	if(b == 0)
		return a;
	else return gcd(b, a%b);
}

int gcd_norec(int a, int b)
{
	if(b == 0)
		return 	a;
	if(a%b == 0)
		return b;
	
	for(int i = b-1; i >=2; i--){
		if(a%i == 0 && b%i == 0)
			return i;
		}
	
	return 1;
}
*/
int gcd_norec2(int a, int b)
{
	int ret;
	while(b)
		ret=a%b,a=b,b=ret; 
	return a;
}

int main()
{
	int n,a,b;

	ifstream fin(FIN);
	ofstream fout(FOUT);
	fin >> n;
	
	for(int i = 1; i <= n; ++i)
		{ 
			fin >> a >> b;
			//fout <<  gcd(a,b)  <<  endl;
			//fout <<  ( (a>b) ? gcd_norec(a,b): gcd_norec(b,a));
			
			fout << gcd_norec2(a,b) << '\n';
		}
		
	return 0;
}