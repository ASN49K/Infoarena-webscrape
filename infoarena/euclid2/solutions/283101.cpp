#include<fstream.h>



main()
{
	ifstream In("euclid2.in");
	ofstream Out("euclid2.out");
	long a,b,r,t;
	In>>t;
	for(int i=1;i<=t;i++)
	{
		In>>a>>b;
		do
		{
			r=a%b;
			a=b;
			b=r;
		}while(r);
		Out<<a<<'\n';
	}
	In.close();
	Out.close();
	return 0;
}

