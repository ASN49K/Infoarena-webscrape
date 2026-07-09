#include<fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int t, a, b;


int euclid(int x,int y){
	int r;
	while(y){
		r=x%y; x=y; y=r;
	}
	
	return x;
}

int main(){
	cin>>t;	
	while(t--){
		cin>>a>>b;
		cout<<euclid(a,b)<<"\n";	
	}
	
	return 0;
}
