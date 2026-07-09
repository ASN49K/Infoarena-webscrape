using namespace std;
#include<fstream>

int main ()
{
	int t,a,b,r,i;
	ifstream in("Euclid2.in");
	ofstream out("Euclid2.out");
	in>>t;
	for(i=1;i<=t;++i)
	{
		in>>a>>b;
		r=a%b;
		while(r){ a=b; b=r; r=a%b; }
		out<<b<<'\n';
	}
	in.close();out.close();
    return 0;
}	
