#include <fstream>
#include <string.h>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout("euclid2.out");

int n, x, y;

int cmmdc(int a, int b){
	if(!b)return a;
	return(cmmdc(b,a%b));
}

int main(){

	cin >> n;
	while(n--){
 	 cin >> x >> y;
 	 cout << cmmdc(x,y) << "\n";
	}
	return (0);
}
