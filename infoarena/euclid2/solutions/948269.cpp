#include<fstream.h>
int i,aux,a,b,t,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main(){
	f>>t;
	for(i=1;i<=t;i++){
		f>>a>>b;
		if(b>a){
			aux=a;
			a=b;
			b=aux;
		}
		while(b){
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<"\n";
	}
	return 0;
}
	