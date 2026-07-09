#include<fstream>
using namespace std;
int main(){
	ifstream f("cmmdc.in");
	ofstream g("cmmdc.out");
	int t,x,y,aux,cmmdc,i,r;
	f>>t;
	for (i=1;i<=t;i++){
		f>>x;
		f>>y;
		if (x<y){
			aux=y;
			y=x;
			x=aux;
		}
		r=x%y;
		while (r!=0){
			x=y;
			y=r;
			r=x%y;
		}
		cmmdc=y;
		g<<cmmdc<<'\n';
		}
	return 0;	
}
