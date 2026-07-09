#include<fstream>
 using namespace std;
  int main()
  {
	  long i,t,a,b;
	  ifstream f("euclid.in");
	  ofstream g("euclid.out");
	  f>>t;
	  for (i=0;i<t;i++)
       {		  
		   f>>a>>b;
		   if (a>b)
		   while (a>b)
			   a=a-b;
		   else if(a<b)
		   while (b>a)
			   b=b-a;
		   if (a<b) g<<a<<endl;
					else g<<b<<endl;
	  }
  }
  