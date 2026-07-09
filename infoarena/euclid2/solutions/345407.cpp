#include<fstream.h>
#include<iostream.h>
void main()
{
	long a,b,i,j,t,max;
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);


	f>>t;

	for(i=1; i<=t; i++)
		{
		 f>>a; f>>b;

		 max=0;

		 if(a > b)
			{
			 for(j=1; j<=b; j++)
				if(b%j==0 && a%j==0 && j>max) max=j;
			 g<<max;
			}

		 else if(a<b)
			{
			 for(j=1; j<=a; j++)
				if(a%j==0 && b%j==0 && j>max) max=j;
			 g<<max;
			}

		 else g<<a;

		 g<<endl;

		}
	f.close();
	g.close();

}


