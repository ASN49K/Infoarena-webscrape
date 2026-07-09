#include<fstream.h>
int main(){
int n,a,b,j,i,c;
ifstream f("euclid2.in");
f>>n;
ofstream g("euclid2.out");
for(i=1;i<=n;i++){
	f>>a;
	f>>b;
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
		}
	g<<a<<"\n";
	}
f.close();
g.close();
return 0;
}