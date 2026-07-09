#include<fstream.h>
int a,b,c,n,i;
int main(){
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++){
		f>>a>>b;
		while(b){
			c=a%b;
			a=b;
			b=c;
		}
		g<<a<<"\n";
	}
	return 0;
}