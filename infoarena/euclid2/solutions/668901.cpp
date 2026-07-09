using namespace std;
#include<fstream>
int main()
{
	long long T,a,b,i;
	ifstream fcin("euclid2.in");
	ofstream fcout("euclid2.out");
	fcin>>T;
	for(i=1;i<=T;i++)
	{
		fcin>>a>>b;
		while(a*b)
			if (a>b)
				a%=b;
			else
				b%=a;
		fcout<<a+b<<"\n";
	}
	fcin.close();
	fcout.close();
	return 0;
}
