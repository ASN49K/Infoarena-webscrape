#include<fstream.h>
#include<math.h>
long n;
long a[500][2];

void euclid(long a,long b)
{
	if(a>b) a=a-b;
		else b=b-a;
		
	if(a==b) g<<a;

}


int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int i;
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
