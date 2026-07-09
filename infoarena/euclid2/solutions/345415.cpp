#include<fstream.h>
#include<iostream.h>
main()
{
	long a,b,i,t,c;
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);

	f>>t;

	for(i=1; i<=t; i++)
		{
		 f>>a; f>>b;
		 while(b)
		    {
		     c=a%b;
		     a=b;
		     b=c;
		    }
		 g<<a<<endl;
		}

	f.close();
	g.close();
	return 0;

}


