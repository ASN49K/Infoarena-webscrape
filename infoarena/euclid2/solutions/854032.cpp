#include<iostream>
#include<cstdio>
using namespace std;
int cmmdc(int a,int b)
{
	int c;
	while(b)
	{
	c=a%b;
	a=b;
	b=c;
	}
	return a;
}
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
int n,i,a,b;
cin>>n;
for(i=0;i<n;i++)
{
	cin>>a>>b;
	cout<<cmmdc(a,b)<<endl;
}
return 0;
}