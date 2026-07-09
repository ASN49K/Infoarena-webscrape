#include<fstream.h>
#include<math.h>
ifstream f("puteri2.in");
ofstream g("puteri2.out");
int t,p;
double n;

int main()
{
  
 f>>t;

 for(register int i=1;i<=t;i++)
  {
    f>>n>>p;
   
 if(p%2==0)
    while(p!=1)
    { n=sqrt(n);
     p/=2;}
    else {double n1;
	  n1=n;
	while(p!=5)
      {n=sqrt(n);
       p/=2;}
	 n=sqrt(n);
	 n=sqrt(n);
	 n=sqrt(n);
     n=ceil(n);
   while(pow(n,p)!=n1)
     {
	n+=1;
	  }
    }
  g<<n<<'\n';
 }
return 0;
}
