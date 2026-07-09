#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t,a,b;
/*
int cmmdc(int x,int y){
	int r;
	while(y){
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}
*/
int cmmdc(int x,int y){
	int r;
	r=x%y;
	x=y;
	y=r;
	if(y)
		return cmmdc(x,y);
	return x;
}
int main(){
	in>>t;
	for(int i=1 ; i<=t ; i++){
		in>>a>>b;
		out<<cmmdc(a,b)<<"\n";
	}
	return 0;
}
