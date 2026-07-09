#include <fstream.h>

int divizor(int &a,int &b)
	{
	while(a!=b)
		{
		if(a>b)
			a=a-b;
		else
			b=b-a;
		}
	return a;
	}

int main()
	{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	int a,b,n;
	in>>n;
	while(n>0)
		{
		in>>a>>b;
		out<<divizor(a,b)<<"\n";
		n--;
		}
	in.close();
	out.close();
	return 0;
	}
