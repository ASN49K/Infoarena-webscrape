#include<fstream>
using namespace std;

int main()
{
	int a,b,c,t,y;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
		in>>t;
		for(c=0; c<t; c++)
		{
			in>>a>>b;			
			while(b!=0)
				{y=a%b;
				a=b;
				b=y;
				}
			out<<a<<"\n";
		}
		in.close();
		out.close();
		return 0;
		
}