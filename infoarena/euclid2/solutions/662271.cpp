#include<fstream>
using namespace std;
int cmmdc( int x,int y){
	for(int r=x%y;r!=0;x=y,y=r,r=x%y);
	return y;
}
int main(){
	int n,x,y,i;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++){
		f>>x>>y;
		g<<cmmdc(x,y)<<"\n";
	}
	return 0;
}

	