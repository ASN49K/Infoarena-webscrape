#include <iostream>
using namespace std;
int cmmdc(int a,int b)
{
	if(a%b==0)
		return b;
	else
		return cmmdc(b,a%b);
}
int main()
{
	int x,y;
	cin>>x;
	cin>>y;
	cout<<cmmdc(x,y);
	return 0;
}
