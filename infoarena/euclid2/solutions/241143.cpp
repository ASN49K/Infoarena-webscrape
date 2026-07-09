#include<fstream>
using namespace std;
int main()
{
	int a,b,n,r,i;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>n;
	for(i=1;i<=n;i++)
	{
		in>>a>>b;
		if(a>b){ aux=a;
		     a=b;
		b=aux;}
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