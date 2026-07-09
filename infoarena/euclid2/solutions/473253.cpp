#include<fstream.h>
#include<math.h>
long n;
long long a[25000][2];

ifstream f("euclid2.in");
	ofstream g("euclid2.out");



int main()
{
	
	long long i;
	f>>n;
	i=0;
	for(i=0;i<n;i++)
	{
		f>>a[i][1]>>a[i][2];
			while(a[i][1]!=a[i][2]){
									if(a[i][1]>1[i][2]) a[i][1]=a[i][1]-a[i][2];
										else a[i][2]=a[i][2]-a[i][1];
		
							}
		g<<a;
			
	}
	
	
	
	f.close();
	g.close();
return 0;
}
