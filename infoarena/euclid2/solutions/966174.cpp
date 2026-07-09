#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
ifstream ff("euclid2.in");
ofstream gg("euclid2.out");

int t,a,b;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	ff >> t;
	while(t--){
		ff >> a >> b;
		gg << gcd(a,b) << "\n";
	}	
	return 0;
}
