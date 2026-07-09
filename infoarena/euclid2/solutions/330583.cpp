#include<fstream>

using namespace std;

ifstream in("euclid3.in");
ofstream out("euclid3.out");

void euclid(int a, int b, int &x, int &y, int &d)
{
	if(b==0)
	{
		x=1;
		y=0;
		d=a;
		return;
	}
	int x2,y2;
	euclid(b,a%b,x2,y2,d);
	x=y2;
	y=x2-a/b*y2;
}

int main()
{
	int a,b,c,d,x,y,T;
	in>>T;
	while(T--)
	{
		in>>a>>b>>c;
		euclid(a,b,x,y,d);
		if(c%d==0)
		{
			out<<c/d*x<<" ";
			out<<c/d*y<<"\n";
		}
		else
		{
		out<<0<<" "<<0<<"\n";
		}
	}
}