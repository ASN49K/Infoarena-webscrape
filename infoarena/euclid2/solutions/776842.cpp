#include<fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a,int b){
	do{
		if(a>b)
			a=a-b;
		if(b>a)
			b=b-a;
	}while(a!=b);
	out<<a<<"\n";
}

int main(){
	
int T,i,a,b;
in>>T;

for(i=1;i<=T;i++){
	in>>a>>b;
	cmmdc(a,b);
}

return 0;
}