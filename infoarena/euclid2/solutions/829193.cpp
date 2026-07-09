#include<fstream>
using namespace std;
int n;
int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		in>>a>>b;
		while(a!=b)
		{
			if(a>b)	a-=b;
			else b-=a;
		}
		out<<a<<" \n";
	}
	return 0;
}