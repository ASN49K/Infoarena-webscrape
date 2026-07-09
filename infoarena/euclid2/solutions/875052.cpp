#include<iostream>
#include<fstream>
using namespace std;
int cmmdc( int a, int b)
{
	
	while( a!=b )
	{
		if( a>b ) a=a-b;
		else b=b-a;
		
	}
	return a;
}
		
int main()
{
	int a,b,n;
	ifstream f( "euclid.in" );
	ofstream g( "euclid.out" );
	f>>n;
	for( int i=1;i<=n;i++)
		{
			f>>a>>b;
			g<<cmmdc(a,b)<<endl;
		}
	f.close();
	g.close();
	return 0;
}
