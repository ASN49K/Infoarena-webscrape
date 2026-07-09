#include<iostream>
#include<cstdio>
using namespace std;
int cmmdc(int a,int b)
{
	while(a!=b)
if(a>b)
	a=a-b;
else
	if(a<b)
		b=b-a;
	return a;
}
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
int n,i,a,b;
for(i=0;i<n;i++)
{
	cin>>a>>b;
	cout<<cmmdc(a,b)<<endl;
}
return 0;
}