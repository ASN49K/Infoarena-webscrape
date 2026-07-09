#include<fstream>

using namespace std;
int main()
{
	long a,b,i,s;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>a;
	while(in>>a>>b)
	{   
		i=2;
		s=1;
		while(a!=1 && b!=1 && a*b)
		{
			while(a%i==0)
			{
				if(b%i==0)
				{	
					s=s*i;
					b=b/i;
				}
				a=a/i;
			}
			i++;
		}
		out<<s<<endl;
	}
	return 0;
}		