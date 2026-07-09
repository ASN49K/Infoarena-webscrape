#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd( int a, int b)
{
    if(!b){
    	return a;
    }
    else{
    	return gcd(b,a%b);
    }
}

int t, a, b;
int main(){
	in >> t;
	for (int i = 0; i < t; i++){
		in >> a >> b;
		out << gcd(a, b);
	}
	return 0;
}