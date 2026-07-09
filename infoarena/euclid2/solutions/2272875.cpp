#include<fstream>
using namespace std;
int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	long long int a,b,r;
	fin>>a;
	fin>>b;
	if(a<b)
		swap(a,b);
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	fout<<a;
	return 0;
}
