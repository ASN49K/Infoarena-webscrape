#include<fstream>
using namespace std;

int t,a,b;

int euclid(int a,int b){
	if(!b) return a;
	return euclid(b,a%b);
}

int main(){
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>t;
	int i;
	for(i=1;i<=t;i++){
		in>>a>>b;
		out<<euclid(a,b)<<endl;
	}
	out.close();
	return 0;
}
