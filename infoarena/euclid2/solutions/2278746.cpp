#include<fstream>
 
using namespace std;
 
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
 
int main()
{
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	unsigned long long a,b,t,i;
	cin>>t;
	for(i=1;i<=t;++i)
	{
		cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	}	
}