#include<fstream>
using namespace std;
int main()
{
	double aux,a ,b,n,r,i;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>n;
	for(i=1;i<=n;i++)
	{
		in>>a>>b;
		
		r=a%b;
		while(r!=0)
		{
			a=b;
			b=r;
			r=a%b;
			
		}
		out<<b<<endl;
	}
	in.close();
	out.close();
	return 0;
}