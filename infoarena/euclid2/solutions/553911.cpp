#include<iostream.h>
#include<fstream.h>
int n,t,y;

int divi(int a,int b)
{
	if(a%b==0) return b;
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
		if(t==0||y==0) g<<'0'<<endl;
		else g<<divi(t,y)<<endl;
    }  
f.close();
g.close();
return 0;
}