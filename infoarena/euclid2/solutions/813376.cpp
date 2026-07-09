#include<fstream>
using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int main()
{
	int a,b,r,c,t;
	fin>>t;
	for(int i=1;i<=t;i++){
	fin>>a>>b;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	c=a;
	if(c==1)c=0;
	fout<<c<<endl;
	}
	return 0;
}