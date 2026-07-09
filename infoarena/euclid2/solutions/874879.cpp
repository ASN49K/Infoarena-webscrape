#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a,int b)
{
	if(b) return gcd(b,a%b);
	return a;
}

int main()
{
	int x;
	int a,b;
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&x);
	//fin>>x;
	while(x)
	{
		//fin>>a>>b; 
		scanf("%d %d",&a,&b);
		
		fout<<gcd(a,b)<<endl;
		//printf("%d\n", gcd(a,b));
		--x;
	}
	//fout.close();
	
	return 0;
}
