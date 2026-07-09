#include<fstream.h>
#include<math.h>
long n;
long long a[25000][2];

ifstream f("euclid2.in");
	ofstream g("euclid2.out");
void euclid(long a,long b)
{
	
	while(a!=b){
	
	if(a>b) a=a-b;
		else b=b-a;
		
	}
	g<<a;
}


int main()
{
	
	long long i;
	f>>n;
	i=0;
	for(i=0;i<n;i++)
	{
		f>>a[i][1]>>a[i][2];
			euclid(a[i][1],a[i][2]);
			
	}
	
	
	
	f.close();
	g.close();
return 0;
}
