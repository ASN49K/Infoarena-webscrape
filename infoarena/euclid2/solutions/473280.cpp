#include<fstream.h>
#include<math.h>
long n;
long a[2500][2];

ifstream f("euclid2.in");
	ofstream g("euclid2.out");


long euclid(long a,long b)
{
	
	        // Condition 1 //
     if ( b == 0 )  return a; 
            else if( a==0 ) return b;
     if(a<b)  return euclid(a,b%a);
              else return euclid(a%b,b);
}

int main()
{
	long a,b;
	long i,j;
	
  i=0;
  f>>n;
  while(i<n)
  {
            
   f>>a;
   f>>b;
   g<<euclid(a,b)<<"\n";
   i++;
   } 
    	
	f.close();
	g.close();
return 0;
}
