#include<fstream>
using namespace std;

int main()
{
	long long a,b,r,n,i;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>n;
	for(i=0;i<n;i++)
	{
    in>>a>>b;
	while(b!=0)
	{
	 r=a%b;
	 a=b;
	 b=r;
	}
	if(a==1)
		a=0;
	out<<a<<'\n';
	}
	return 0;
}
