#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int x[100],y[100],n,i;
void citire()
{
	fin>>n;
	for(i=1; i<=n; i++)
		fin>>x[i]>>y[i];
}
int cmmdc(int a, int b)
{
	if(a%b==0)
		return b;
	else
		return cmmdc(b,a%b);
}
int main()
{
	citire();
	for(i=1; i<=n; i++)
		fout<<cmmdc(x[i],y[i])<<'\n';
	fin.close();
	fout.close();
	return 0;
}
