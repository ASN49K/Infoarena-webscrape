#include<fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
	int r;
	while(b)
	{
		    r=a%b;
		    a=b;
		    b=r;
	}
return a;
}
int main()
{

int t,x,y;
in>>t;
	while(t>0)
	{
	in>>x;
	in>>y;
	out<<euclid(x,y);
	t--;
	}
    in.close();
    out.close();
	return 0;
}