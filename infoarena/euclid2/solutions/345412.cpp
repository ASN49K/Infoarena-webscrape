#include<fstream.h>
#include<iostream.h>
main()
{
	long a,b,i,t;
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);

	f>>t;

	for(i=1; i<=t; i++)
		{
		 f>>a; f>>b;

		 if(a%b==0)g<<b;

		 else if(b%a==0)g<<a;

		 else if(a > b)
			{
			 while(a>b)a=a-b;
			 g<<a;
			}

		 else if(a<b)
			{
			 while(b>a)b=b-a;
			 g<<b;
			}

		 else g<<a;

		 g<<endl;

		}
	f.close();
	g.close();
	return 0;

}


