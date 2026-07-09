#include <iostream>
#include <fstream>
using namespace std;
int T,a,b;
int cmmdc(int x, int y)
{
	int min=x<y?x:y;
	for(int i=min;i>=1;i--)
		if(x%i==0 && y%i==0) return i;
	return 1;
}
int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++)
		{
			cin>>a>>b;
			cout<<cmmdc(a,b)<<"\n";
		}
	return 0;
}
		