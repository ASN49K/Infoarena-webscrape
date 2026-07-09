#include<fstream.h>
int main(){
	ifstream f("cmmdc.in");
	ofstream g("cmmdc.out");
	int a , b;
	f>>a>>b;
	while(a!=b){
		if(a>b)
			a=a-b;
		else	
			b=b-a;
	}
	g<<a;
	f.close();
	g.close();
	return 0;

}