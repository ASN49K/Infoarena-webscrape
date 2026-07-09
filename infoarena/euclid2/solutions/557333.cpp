#include<iostream>
using namespace std;
int t,b,a,i,r;
int main()
{
	for(i=1;i<=t;i++)
		cin>>a>>b;
	 r=a%b;
	 while(r)
	 {a=b;b=r;r=a%b;}
	 cout<<a<<' '<<b<<'\n';  

return 0;

}
