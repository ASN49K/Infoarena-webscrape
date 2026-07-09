#include<fstream>

using namespace std;

	
			
int cmmdc(int a, int b)
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
{	int a,b;
			ifstream f("cmmdc.in");
			ofstream g("cmmdc.out");

		f>>a;
		f>>b;
		
		if(cmmdc(a,b)==1)
			g<<0;
		else
			g<<cmmdc(a,b);
			
				f.close();
				g.close();
		
		
	
	return 0;
}