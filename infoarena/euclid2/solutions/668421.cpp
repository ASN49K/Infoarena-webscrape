using namespace std;
#include<fstream>
int main()
{
	ifstream fcin("euclid2.in");
	ofstream fcout("euclid2.out");
	long T,i,b,a;
	fcin>>T;
	for(i=1;i<=T;i++)
	{
		fcin>>a>>b;
		while (a*b)
			if (a>b)
				a%=b;
			else
				b%=a;
		fcout<<a+b<<"/n";
	}
	fcin.close();
	fcout.close();
	return 0;
}