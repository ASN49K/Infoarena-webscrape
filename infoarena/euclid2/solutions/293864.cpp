#include<fstream.h>
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
long t,a,b,i,c;

int main ()
{
    in>>t;
    for(i=1;i<=t;i++)
    {
		     in>>a>>b;
		     if(b>a)
			    {
			    c=a;
			    a=b;
			    b=c;
			    }
		     c=1;
		     while(c)
			  {
			  c=a%b;
			  a=b;
			  b=c;
			  }
		     out<<c<<"\n";
    }
return 0;
}
