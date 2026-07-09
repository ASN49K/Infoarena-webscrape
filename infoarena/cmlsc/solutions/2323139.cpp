#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int main() {
    int  n , k ;
	f >> n;
	f >> k;
	int a[n] , b[k] , c[max(n , k)] ;
	for(int i = 0; i < n ; i++){
        f >> a[i] ;
	}

	for(int i = 0 ; i < n ; i++){
        f >> b[i] ;
	}
	int z = 0 ;
	for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < k ; j++)
            if(a[i] == b[j]){
                c[z] = a[i] ;
                z++ ;
            }
    g << z << endl ;
    for(int i = 0 ; i < z ; i++){
        g << c[i] << " " ;
    }
}
