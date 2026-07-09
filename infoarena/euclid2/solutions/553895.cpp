#include<iostream.h>
#include<fstream.h>
int n,t,y;

int divi(int r,int a,int b)
{
	if(r==0) return b;
	else return divi(a%b,b,r);
	
}

int main()
{
	ifstream f;
	f.open("euclid2.in");
	ofstream g;
	g.open("euclid2.out");
	f>>n;
	while(!f.eof()){
		f>>t>>y;
		g<<divi(t%y,t,y)<<endl;
    }  
f.close();
g.close();
return 1;
}