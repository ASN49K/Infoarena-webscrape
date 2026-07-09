#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t,a,b;
int gcd(int a,int b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<gcd(a,b)<<'\n';
	}
	return 0;
}
