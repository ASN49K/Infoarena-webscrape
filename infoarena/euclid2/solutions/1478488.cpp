#include <fstream>

using namespace std;



long gcd(long a, long b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

int main(void){
	
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	
	ios::sync_with_stdio(false);
	
	int t,a,b;	

	in >> t;
	
	for (int i=0; i<t; i++){
		in >> a >> b;
		out << /*gcd(a, b) <<*/ endl;		
	}
	
	in.close();
	out.close();
	
	return 0;
}
