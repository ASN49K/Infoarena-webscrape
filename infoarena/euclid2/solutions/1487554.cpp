#include<fstream>
using namespace std;
int cmmdc(int a,int,b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main()
{
	int a,b,n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		cout<<cmmdc(a,b)<<"\n";
	}
	return 0;
}