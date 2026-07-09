#include<fstream>
using namespace std;

int f(int x, int y){
	while(x != y){
		if(x > y) x -= y;
		else y -= x;
	}
	
return x;
}

int main(){
	fstream in("euclid2.in", ios::in), out("euclid2.out", ios::out);
	int n; int a, b;
	in >> n;
	for(int i = 0; i < n; i++){
		in >> a >> b;
		out << f(a, b) << endl;
	}
}
