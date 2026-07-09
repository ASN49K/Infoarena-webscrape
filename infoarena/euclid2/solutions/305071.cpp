#include<fstream>
using namespace std;
int main()
{
	int a, b,t,r,i;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>t;
	for(i=1;i<=t;i++)
		{ in>>a>>b;
		   r=a%b;
		   while(r)
			   { a=b;
				b=r; 
				r=a%b;
			   }out<<b<<"\n";
		}
in.close();
out.close();
return 0;
}
