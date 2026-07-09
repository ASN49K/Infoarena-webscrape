#include<fstream>
using namespace std;
long cmm(long a,long b)
{while(a!=b)
		if(a>b)
			a-=b;
		else
			b-=a;
	return a;
}
int main(){
	long a,b,t;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(int i=0;i<t;i++){
		f>>a>>b;
	    g<<cmm(a,b)<<"\n";
	}
	g<<"\n";
	f.close();
	g.close();
	
}