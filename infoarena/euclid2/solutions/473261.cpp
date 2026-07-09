#include<fstream.h>
#include<math.h>
long n;
long long a[25000][2];

ifstream f("euclid2.in");
	ofstream g("euclid2.out");


long long euclid(long long a,long long b)
{
	
	if(a==b) return a;
	else{
		if(a>b) return euclid(a-b,b);
			else return euclid(a,b-a);
		
		}
}

int main()
{
	
	long long i;
	f>>n;
	i=0;
	for(i=0;i<n;i++)
	{
		f>>a[i][1]>>a[i][2];
			
		g<<euclid(a[i][1],a[i][2]);
			
	}
	
	
	
	f.close();
	g.close();
return 0;
}
