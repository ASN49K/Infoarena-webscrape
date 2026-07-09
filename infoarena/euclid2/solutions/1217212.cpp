#include<fstream>
using namespace std;

//input/output files
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int aux,n,x,y;

int cmmdc(int a, int b)
{
	if(b == 0)
	{
        return a;
	}
	else return cmmdc(b, a % b);

}

int main()
{
	f >> n;

	for(int i = 1; i <= n; i++)
	{
		f >> x;
		f >> y;
		g << cmmdc(x,y) << endl;
	}


		return 0;
}
