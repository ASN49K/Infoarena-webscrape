#include<fstream>
using namespace std;
int main () {
	int a,b,r,x,y,c;
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>a; 
	cin>>b;
	if (a>=b) {r=b;}
	if (a<b) {r=a;}
		for (x=0;x<=b;x++)
			for (y=1;y>=(-a);y--){
				if( ( (a*x)+(b*y) )<r)
				if( ( (a*x)+(b*y) )>0) 
				r=(a*x)+(b*y);}
	cout<<r;
	return 0;
}