#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n;

void cmmdc(int x,int y){
	if(y==0){
		out<<x<<"\n";
		return;
	}
	cmmdc(y,x%y);
}

int main(){
	int x,y,i;
	in>>n;
	for(i=1;i<=n;i++){
		in>>x>>y;
		if(x==0 || y==0){
			out<<"0\n";
			continue;
		}
		if(x==1 || y==1){
			out<<"1\n";
			continue;
		}
		cmmdc(x,y);
	}
	return 0;
}
