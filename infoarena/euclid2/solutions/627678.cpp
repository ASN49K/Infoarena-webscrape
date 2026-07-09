#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,j,max1,k,i;
int main()
{
	f>>t; max1=1;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		if(a<b)
		{
			for(j=1;j<=a;j++)
			{
				if(a%j==0 && b%j==0)
				{
					if (j>max1)
						max1=j;
					else
					max1=1;
				}
				
            }
		}
		else
		{
			for(k=1;k<=b;k++)
			{
				if(a%k==0 && b%k==0)
				{
					if (k>max1)
						max1=k;
					else
					max1=1;
	            }
	        }
        }	
			
		g<<max1<<'\n';	
	}
return 0;
}