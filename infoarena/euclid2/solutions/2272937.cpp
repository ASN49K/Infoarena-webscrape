#include<fstream>
using namespace std;

 int cmmdc( int a,int b)
{
	if(!b)
		return a;
	return cmmdc(b,a%b);
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	 int t,a,b,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		fin>>a;
		fin>>b;
		fout<<cmmdc(a,b)<<endl;
	}
	return 0;
}
