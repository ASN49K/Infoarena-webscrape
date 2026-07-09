#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a , int b){
    while(b){
        int r = a% b ;
        a= b ;
        b = r;
    }

    return a ;
}

int a , b , n ;
int main() {
	f >> n;
	for(; n > 0 ; n--){
        f >> a >> b ;
        g << cmmdc(a,b) << "\n" ;
	}
}
