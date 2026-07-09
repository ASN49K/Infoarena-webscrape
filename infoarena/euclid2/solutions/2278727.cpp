#include<fstream>

using namespace std;

int euclid(int a, int b)
{
	int r=1;
	while(r)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	int a,b;
	cin>>a>>b;
	cout<<euclid(a,b);
	
}