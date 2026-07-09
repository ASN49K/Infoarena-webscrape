#include<iostream.h>
#include<fstream.h>
int n,t,y;

int divi(int a,int b)
{
	if(!b) return a;
	else return divi(b,a%b);
	
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
		if(t==0||y==0) g<<'0'<<'\n';
		else g<<divi(t,y)<<'\n';
    }  
f.close();
g.close();
return (0);
}