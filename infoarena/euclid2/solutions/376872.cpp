#include <iostream> 
using namespace std;
int cmmdc(int a,int b)
{
	int r;
	while((r=a%b)!=0)
	{
		a=b;
		b=r;
	}
	return b;
}
int main()
{
	int a,i,b,c;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	cin>>a;
	for(i=0;i<a;++i)
	{
		cin>>b>>c;
		cout<<cmmdc(b,c)<<endl;
	}
	return 0;
}